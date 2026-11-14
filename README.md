*This project has been created as part of the 42 curriculum by pspuhler, juan-jos.*

# Push_swap

## Description

**Push_swap** is an algorithmic complexity and data-structure project in the 42 curriculum. The objective is to sort a stack of unique signed integers (`stack_a`) in ascending order using an auxiliary empty stack (`stack_b`) and a restricted set of $11$ stack manipulation instructions (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`), while minimizing the total number of generated operations.

To demonstrate a rigorous practical understanding of asymptotic complexity within the **Push_swap operation model** (where time complexity is measured by the number of stack instructions emitted rather than raw CPU cycles), this implementation embeds four distinct sorting strategies selectable at runtime:
1. **Simple Strategy (`--simple`):** Shortest-path Selection / Min-Extraction Sort in $O(n^2)$ operations.
2. **Medium Strategy (`--medium`):** Hourglass Chunk-Based Sort in $O(n\sqrt{n})$ operations.
3. **Complex Strategy (`--complex`):** Least Significant Digit (LSD) Binary Radix Sort in $O(n \log n)$ operations.
4. **Adaptive Strategy (`--adaptive`, default):** A disorder-driven hybrid router that measures the initial inversion ratio of `stack_a` before executing any move and dispatches the optimal regime ($O(n^2)$ for low disorder, $O(n\sqrt{n})$ for medium disorder, and $O(n \log n)$ for high disorder).

Additionally, the program features a built-in **Benchmark Mode (`--bench`)** that outputs the initial disorder percentage, the active strategy and its theoretical complexity class, the total operation count, and an exact per-instruction breakdown to `stderr`.

---

## Instructions

### Compilation

The project is written in C in strict compliance with the 42 Norm and compiles via the provided `Makefile` using `cc` with `-Wall -Wextra -Werror`. It automatically builds the bundled `libft` library first without unnecessary relinking.

```bash
# Compile the push_swap executable
make

# Remove object files (.o)
make clean

# Remove object files, push_swap binary, and libft.a
make fclean

# Recompile everything from scratch
make re
```

### Execution & CLI Flags

The program takes optional strategy/benchmark flags followed by a list of signed 32-bit integers representing `stack_a` (where the first integer is at the top of the stack):

```bash
./push_swap [FLAGS] <int_1> <int_2> ... <int_n>
```

| Flag | Description | Complexity Class (Push_swap Model) |
| :--- | :--- | :--- |
| `--adaptive` | **(Default)** Selects the sorting strategy dynamically based on initial stack disorder. | Regime-dependent: $O(1)$, $O(n^2)$, $O(n\sqrt{n})$, or $O(n \log n)$ |
| `--simple` | Forces the baseline Selection / Min-Extraction algorithm. | $O(n^2)$ |
| `--medium` | Forces the Hourglass Chunk-Based algorithm. | $O(n\sqrt{n})$ |
| `--complex` | Forces the LSD Binary Radix algorithm. | $O(n \log n)$ |
| `--bench` | Outputs disorder percentage, selected strategy, total moves, and per-operation counts to `stderr` (`fd 2`). Can be combined with any strategy flag. | N/A (Diagnostic Flag) |

### Usage Examples

```bash
# 1. Default adaptive execution
./push_swap 2 1 3 6 5 8

# 2. Force a specific strategy and count generated operations
ARG="4 67 3 87 23"
./push_swap --adaptive $ARG | wc -l

# 3. Verify correctness with the 42 checker while inspecting benchmark metrics
ARG=$(shuf -i 0-9999 -n 100)
./push_swap --bench --medium $ARG | ./checker_linux $ARG

# 4. Run 500 random numbers in benchmark mode, saving metrics to bench.txt
shuf -i 0-9999 -n 500 > args.txt
./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
cat bench.txt

# 5. Error handling (non-numeric arguments, duplicates, or 32-bit int overflow)
./push_swap --adaptive 0 one 2 3
# Outputs "Error\n" to stderr and exits with code 1
```

---

## Technical Architecture & Code Walkthrough

Because global variables are strictly forbidden, the entire program state is encapsulated in a single master structure `t_data` (`push_swap.h`) passed by reference across modules.

### 1. Circular Doubly Linked List ("Infinite Linked List") — `list_make.c` & `stack_moves.c`

A central architectural design implemented by `juan-jos` is the representation of `stack_a` and `stack_b` as **Circular Doubly Linked Lists** (`t_node`), where every node holds:
* `int value`: The raw integer during parsing/disorder calculation, later overwritten with its normalized rank $[0, n - 1]$.
* `int index`: Used by the medium chunk-sorting strategy to store the rank.
* `struct s_node *next` and `struct s_node *prev`: Bidirectional pointers forming a closed ring.

```text
       +---------------------------------------------------+
       |                                                   |
       v                                                   |
   [ HEAD (Top) ] <===> [ Node 2 ] <===> ... <===> [ TAIL (Bottom) ]
       |                                                   ^
       +---------------------------------------------------+
```



### 2. Dynamic Operation Recording & Safe Combined Moves — `record.c` & `ops_*.c`

Instead of printing instructions immediately to `stdout`, every stack wrapper (`sa`, `pb`, `ra`, etc.) records its enum identifier (`t_op` from `OP_SA` to `OP_RRR`) into a dynamically resizing array `data->ops` managed in `record.c`:
* `init_data()` allocates an initial buffer for $1024$ operations.
* When `data->n_ops == data->capacity`, `record()` doubles the buffer capacity (`capacity * 2`), copies existing operations via `ft_memcpy()`, and frees the old buffer.
* **Why record instead of immediate printing?** Recording all moves as compact integers enables `print_ops()` to flush the entire instruction stream cleanly after sorting and allows `print_bench()` (`bench.c`) to tally exact operation histograms in a single pass without global counters.
* **Defensive Combined Moves (`ss`, `rr`, `rrr`):** In `ops_swap_push.c`, `ops_rotate.c`, and `ops_rev_rotate.c`, each low-level primitive returns `1` if a move actually occurred or `0` if the stack had fewer than $2$ elements. If `rr(data)` is called when only `stack_a` can rotate (`a_move == 1, b_move == 0`), the wrapper accurately records `OP_RA` instead of `OP_RR`.

### 3. Input Parsing, Validation & Coordinate Compression — `parse.c` & `rank.c`

* **Flag Parsing (`parse_flags` in `parse.c`):** Scans leading arguments starting with `"--"`. The helper `is_flag()` compares `ft_strlen(name) + 1` bytes via `ft_strncmp` to include the null terminator `'\0'`, ensuring prefixes like `--simple123` are rejected as errors. Multiple flags (such as `--bench --complex`) can be combined in any order before the integer list.
* **Overflow-Safe Integer Parsing (`ft_atoi_safe` in `parse.c`):** Parses optional `'+'` or `'-'` signs, rejects empty strings or lone signs, and accumulates digits into a `long`. Crucially, the range check (`result * sign > INT_MAX || result * sign < INT_MIN`) is evaluated **inside the loop on every character**, preventing 64-bit `long` wrap-around even on 30-digit numbers.
* **Duplicate Detection (`duplicate_checker` in `parse.c`):** Traverses the circular list using `outer` and `inner` pointers (`while (outer->next != head)` and `while (inner != head)`) to guarantee all elements are strictly unique.
* **Rank Normalization (`assign_ranks` in `rank.c`):** Before executing the sorting strategy, arbitrary signed integers (e.g., `{-2147483648, 42, 2147483647}`) are mapped to their 0-based sorted ranks $\{0, 1, \dots, n - 1\}$ by counting how many elements in `stack_a` are strictly smaller (`count_smaller`). A temporary heap array `ranks` stores all computed ranks before overwriting `current->value`, ensuring earlier overwrites do not corrupt subsequent comparisons. This normalization is essential for bitwise Radix Sort (`sort_complex`), which cannot directly shift negative two's-complement numbers.

### 4. Benchmark Formatting Without `printf("%f")` — `bench.c`

Because standard `printf` is forbidden and `ft_putnbr_fd` only prints integers, `put_percent()` in `bench.c` converts the floating-point disorder ratio $\in [0.0, 1.0]$ into fixed-point hundredths of a percent with half-up rounding:
$$\text{hundredths} = \lfloor \text{disorder} \times 10000.0 + 0.5 \rfloor$$
It then prints the integer part (`hundredths / 100`), a decimal point `'.'`, a leading `'0'` if `hundredths % 100 < 10`, and the fractional part (`hundredths % 100`) to `stderr` (`fd = 2`).

---

## Disorder Metric & Sorting Strategies (Algorithmic Analysis)

All complexity bounds below are analyzed strictly within the **Push_swap Operation Model** (number of stack instructions emitted) and **Auxiliary Space Model** (additional memory beyond the input stacks).

### 1. Disorder Metric — `compute_disorder.c`

Before any move is executed (and before rank replacement), `compute_disorder()` measures how far `stack_a` is from ascending order by counting **inversions** (pairs $(i, j)$ with $0 \le i < j < n$ such that $a[i] > a[j]$):

$$\text{Disorder} = \frac{\text{mistakes}}{\text{total\_pairs}}, \quad \text{where } \text{total\_pairs} = \frac{n(n - 1)}{2}$$

* If $n < 2$ or `stack_a` is already sorted, $\text{mistakes} = 0 \implies \text{Disorder} = 0.00$ ($0.00\%$).
* If `stack_a` is sorted in strictly descending order, every pair is inverted $\implies \text{Disorder} = 1.00$ ($100.00\%$).

### 2. Simple Strategy (`--simple`): Shortest-Path Selection Sort — `algorithm_simple.c`

* **Internal Technique:**
  1. In each pass over the remaining $k$ elements in `stack_a`, `get_min_pos()` scans the circular list to find the 0-based index `min_pos` of the minimum element.
  2. `move_min_to_top()` compares `min_pos` against $k / 2$: if the minimum lies in the top half ($\text{min\_pos} \le k / 2$), it rotates upward using `ra`; if it lies in the bottom half, it reverse-rotates downward using `rra`.
  3. Once at the top, `pb` pushes the minimum onto `stack_b`.
  4. After $n - 1$ extractions, only the largest element remains in `stack_a`, and $n - 1$ `pa` operations push all elements back onto `stack_a` in sorted order.
* **Time Complexity (Push_swap Operations) — $O(n^2)$:**
  Extracting the $i$-th minimum from a stack of size $k = n - i$ requires at most $\lfloor k / 2 \rfloor$ rotations plus $1$ `pb` and $1$ `pa`. Summing over all $n - 1$ steps yields the upper bound:
  $$T_{\text{simple}}(n) \le \sum_{k=2}^{n} \left( \left\lfloor \frac{k}{2} \right\rfloor + 2 \right) = \frac{n^2}{4} + O(n) = O(n^2) \text{ operations.}$$
* **Space Complexity — $O(1)$ Auxiliary Space:**
  Uses only scalar loop variables (`min_val`, `min_pos`, `pos`) on the call stack and moves existing nodes between `stack_a` and `stack_b` in-place.

### 3. Medium Strategy (`--medium`): Hourglass Chunk Sort — `algorithm_medium.c`

* **Internal Technique:**
  1. **Chunk Partitioning:** `sort_medium()` computes the integer square root via `ft_sqrt(n)` and partitions the normalized rank range $[0, n - 1]$ into $C = \max(1, \lfloor \sqrt{n} / 2 \rfloor)$ chunks, each of width $S = \lceil n / C \rceil = \Theta(\sqrt{n})$.
  2. **Phase 1 — Hourglass Pre-Sort to `stack_b` (`push_chunks`):** For each chunk $i \in \{1, \dots, C\}$ with upper rank bound $\text{limit} = i \cdot S$, `stack_a` is scanned. Whenever the top element belongs to the active chunk ($\text{index} < \text{limit}$), it is pushed to `stack_b` via `pb`. Immediately after pushing, if the element belongs to the **lower half** of the current chunk ($\text{index} < \text{limit} - S / 2$), `rb` rotates it to the bottom of `stack_b`. Elements outside the chunk are skipped via `ra`. This creates an "hourglass" distribution in `stack_b` where larger chunks wrap around both the top and bottom extremes of `stack_b`.
  3. **Phase 2 — Greedy Max Reinsertion (`push_back_to_a`):** While `stack_b` is non-empty, `get_max_val()` and `get_node_pos()` locate the current maximum in `stack_b`, rotate it to the top via the shortest path (`rb` if $\text{pos} \le \text{size\_b} / 2$, else `rrb`), and push it back to `stack_a` (`pa`).
* **Time Complexity (Push_swap Operations) — $O(n\sqrt{n})$:**
  * **Phase 1:** There are $C = \Theta(\sqrt{n})$ chunks. Completing each chunk requires at most one full rotation of `stack_a` ($\le n$ `ra` moves), plus overall $n$ `pb` moves and at most $n / 2$ `rb` moves across all chunks:
    $$T_{\text{phase 1}}(n) \le C \cdot n + \frac{3}{2}n = \Theta(n\sqrt{n}) \text{ operations.}$$
  * **Phase 2:** Because chunks were pushed in rank ranges of size $S = \Theta(\sqrt{n})$ and split across the top and bottom of `stack_b`, the maximum remaining element in `stack_b` is always within distance $O(S) = O(\sqrt{n})$ of either the top or bottom of `stack_b`. Extracting all $n$ elements takes $n \cdot O(\sqrt{n}) = O(n\sqrt{n})$ rotations plus $n$ `pa` moves.
  * **Total Upper Bound:** $T_{\text{medium}}(n) = O(n\sqrt{n})$ operations (averaging $\approx 642$ operations for $n = 100$).
* **Space Complexity — $O(1)$ Auxiliary Space:**
  Rank indices are stored directly inside each pre-allocated `t_node->index` field; no extra heap buffers are allocated.

### 4. Complex Strategy (`--complex`): LSD Binary Radix Sort — `algorithm_complex.c`

* **Internal Technique:**
  1. Operates on the normalized non-negative ranks $[0, n - 1]$ assigned by `assign_ranks()`.
  2. `get_max_bits(n)` calculates the exact number of binary bits $B = \lceil \log_2(n) \rceil$ required to represent the maximum rank $n - 1$.
  3. For each bit position $\text{bit} \in \{0, 1, \dots, B - 1\}$ from Least Significant Bit (LSB) to Most Significant Bit (MSB):
     * Iterates through all $n$ elements currently in `stack_a`.
     * Inspects the current bit via `((data->stack_a->value >> bit) & 1)`:
       * If the bit is `0`, the element is pushed to `stack_b` (`pb`).
       * If the bit is `1`, the element is rotated to the bottom of `stack_a` (`ra`).
     * Once all $n$ elements have been partitioned, all elements in `stack_b` are pushed back to `stack_a` via `pa`, preserving the stable relative order established by earlier bit passes.
* **Time Complexity (Push_swap Operations) — $O(n \log n)$:**
  There are $B = \lceil \log_2(n) \rceil$ passes. In each pass, every element is inspected once ($n$ operations of either `pb` or `ra`), and every `0`-bit element in `stack_b` (at most $n$, on average $n / 2$) is pushed back via `pa`. Thus, each pass costs between $1.5n$ and $2n$ operations:
  $$T_{\text{complex}}(n) \le 2n \lceil \log_2(n) \rceil = O(n \log n) \text{ operations.}$$
  For $n = 100$ ($B = 7$), this yields $\approx 1084$ operations; for $n = 500$ ($B = 9$), this yields $\approx 6784$ operations (matching the subject's reference benchmark).
* **Space Complexity — $O(1)$ Auxiliary Space inside `sort_complex` ($O(n)$ total with `assign_ranks`):**
  The radix pass itself uses $O(1)$ extra space (`n`, `max_bits`, `bit`, `i`), while the prerequisite coordinate compression in `assign_ranks()` temporarily allocates one `int` array of size $n$ ($O(n)$ space), which is freed before `sort_complex()` begins.

### 5. Custom Adaptive Strategy (`--adaptive`): Disorder-Based Regime Switching — `main.c`

Implemented in `execute_strategy()` (`main.c`), the adaptive strategy inspects `disorder` before performing any stack moves and routes execution across four regimes:

| Regime | Disorder Condition | Selected Internal Method | Operation Complexity | Auxiliary Space |
| :--- | :--- | :--- | :--- | :--- |
| **Sorted** | $\text{Disorder} = 0.0$ (`is_sorted`) | Early exit (`None`) | $O(1)$ ($0$ ops) | $O(1)$ |
| **Low Disorder** | $0.0 < \text{Disorder} < 0.2$ | `sort_simple` (Selection / Min-Extraction) | $O(n^2)$ | $O(1)$ |
| **Medium Disorder** | $0.2 \le \text{Disorder} < 0.5$ | `sort_medium` (Hourglass Chunk Sort) | $O(n\sqrt{n})$ | $O(1)$ |
| **High Disorder** | $\text{Disorder} \ge 0.5$ | `sort_complex` (LSD Binary Radix Sort) | $O(n \log n)$ | $O(1)$ |


## Resources & AI Usage

### Classic References
* **42 Curriculum Subject**, *Push_swap — Because Swap_push doesn’t feel as natural (Version 1.1)*.

### Use of Artificial Intelligence (Chapter III Compliance)
1. **Conceptual Research & Complexity Modeling:** Used to discuss the difference between classical RAM-model time complexity and the Push_swap operation-count model, particularly verifying the $O(n\sqrt{n})$ upper bound of two-phase chunk sorting and the $O(n \log n)$ bound of base-2 LSD Radix Sort.
2. **Automated Testing & Edge-Case Auditing:** Used to generate shell and Python verification harnesses to stress-test edge cases (`INT_MAX`/`INT_MIN` overflows, `-0` vs `0` duplicates, single-element stacks, empty arguments, and Valgrind leak checks on error exits).
3. **Documentation Structuring:** Used to help structure and format the mathematical complexity arguments and technical architecture explanations in this `README.md`.

---

## Team Git Workflow

1. **Update Project:** `git checkout main` $\rightarrow$ `git pull`
2. **Create Branch:** `git checkout -b <new-branch-name>`
3. **Publish Branch:** `git push origin <new-branch-name>`
4. **Stage & Commit Changes:** `git add`, `git commit`, `git push`
5. **Pull Request:** Open PR on GitHub $\rightarrow$ Compare & pull request $\rightarrow$ assign partner as Reviewer
6. **Peer Review:** Reviewer inspects code, tests Norminette & Valgrind, and approves
7. **Branch Cleanup:** Delete merged remote branch and clean local branch
