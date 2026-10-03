*This project has been created as part of the 42 curriculum by pspuhler.*

# ☄️ Libft

## 🛸 Description
42 school's first project in the common core. **Libft** is a custom C library recreating essential standard functions from scratch. The goal? Deeply understand memory management, pointers, and data structures while building a rock-solid toolkit for all future 42 projects. No shortcuts and strictly Norminette-compliant.

## 🌕 The Architecture (What is what?)
Before using the library, here is a quick breakdown of the core files:

| File | What it does |
| :--- | :--- |
| `libft.h` | **The Header:** Acts as the table of contents. It contains all function prototypes and the `t_list` struct. You `#include` this in your future `.c` files. |
| `Makefile` | **The Automator:** A script that compiles all `.c` files using strict flags (`-Wall -Wextra -Werror`). It saves you from typing massive compile commands. |
| `libft.a` | **The Archive:** The final compiled library. It bundles all your compiled functions into one static file that you link to your new projects. |

## 🚀 Instructions & How to Use
**1. Compile the library:**
Clone the repo and run the Makefile to generate the `libft.a` file.
*   **Tech Stack:** `C`, `gcc`/`cc`, `ar`
*   **Compilation Flags:** `-Wall -Werror -Wextra`

| Command | Action |
| :--- | :--- |
| `make` | Compiles functions into `libft.a`. |
| `make clean` | Removes all `.o` object files. |
| `make fclean` | Removes `.o` files AND the `libft.a` binary. |
| `make re` | Performs `fclean` then `make` (full rebuild). |

**2. Use it in your code:**
Include the header in your `.c` file:
```
#include "libft.h"
```
**3. Compile your project with Libft:**
Use the following command to link the library to your program.
(Note: `-L` tells the compiler to look in the current directory for the library, and `-lft` links the libft.a file) include the header in your `.c` file:
```
cc -Wall -Wextra -Werror your_code.c -L. -lft -o your_program
```

## 👾 The Library (Technical Details)
This library is split into three parts: core libc functions, additional utility functions and linked list manipulation.

### Part 1: Libc Functions (Standard C Library)
Reimplementations of standard C library functions.

| Category | Functions |
| :--- | :--- |
| **Memory** | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| **Strings** | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| **Type Check/Conv** | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`, `ft_atoi` |

### Part 2: Additional Functions
Custom utility functions for string manipulation and file descriptor outputs.

| Category | Functions |
| :--- | :--- |
| **String Ops** | `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split` |
| **Mapping** | `ft_strmapi`, `ft_striteri` |
| **Conversion** | `ft_itoa` |
| **Output (FD)** | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` |

### Part 3: Linked Lists
Tools to create, iterate, and destroy `t_list` structures.

| Category | Functions |
| :--- | :--- |
| **Create/Add** | `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back` |
| **Read/Search** | `ft_lstsize`, `ft_lstlast` |
| **Iterate/Map** | `ft_lstiter`, `ft_lstmap` |
| **Delete** | `ft_lstdelone`, `ft_lstclear` |

## 🔮 Resources
*   **Documentation:** `man` pages (e.g., `man 3 memcpy`)
*   **AI Usage:** Gemini was used for peer review: checking Nthe Makefile, exercising edge cases such as `INT_MIN`, high-bit characters, zero-sized `calloc` requests, and allocation failures.
