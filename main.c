/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 18:25:18 by pspuhler          #+#    #+#             */
/*   Updated: 2026/11/10 10:29:52 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(char *label, t_node *head)
{
	t_node	*current;

	printf("%s: ", label);
	if (!head)
	{
		printf("(empty)\n");
		return ;
	}
	current = head;
	while (1)
	{
		printf("%d", current->value);
		current = current->next;
		if (current == head)
			break ;
		printf(" ");
	}
	printf("\n");
}

void	print_stack_rev(char *label, t_node *head)
{
	t_node	*start;
	t_node	*current;

	printf("%s rev: ", label);
	if (!head)
	{
		printf("(empty)\n");
		return ;
	}
	start = head->prev;
	current = start;
	while (1)
	{
		printf("%d", current->value);
		current = current->prev;
		if (current == start)
			break ;
		printf(" ");
	}
	printf("\n");
}

/*
** Checks the first argument for strategy flags and sets the start index
** for the number parsing accordingly.
*/
int	parse_mode(int argc, char **argv, int *start_idx)
{
	*start_idx = 1;
	if (argc > 1 && ft_strncmp(argv[1], "--", 2) == 0)
	{
		*start_idx = 2;
		if (ft_strncmp(argv[1], "--simple", 9) == 0)
			return (MODE_SIMPLE);
		if (ft_strncmp(argv[1], "--medium", 9) == 0)
			return (MODE_MEDIUM);
		if (ft_strncmp(argv[1], "--complex", 10) == 0)
			return (MODE_COMPLEX);
		if (ft_strncmp(argv[1], "--adaptive", 11) == 0)
			return (MODE_ADAPTIVE);
		*start_idx = 1;
	}
	return (MODE_ADAPTIVE);
}

/*
** Directs the program to the correct algorithm based on mode and disorder.
*/
void	execute_strategy(t_data *data, int mode, float disorder)
{
	if (mode == MODE_SIMPLE)
		sort_simple(data);
	// else if (mode == MODE_MEDIUM)
	// 	sort_medium(data);
	// else if (mode == MODE_COMPLEX)
	// 	sort_complex(data);
	// else if (mode == MODE_ADAPTIVE)
	// 	sort_adaptive(data, disorder);
}

/*
** Main entry point. Initializes data structures, parses CLI arguments
** including strategy flags, and routes to the correct sorting algorithm.
*/
int main(int argc, char **argv)
{
    t_data  data;
    int     mode;
    int     start_idx;
    float   disorder;

    if (argc < 2)
        return (0);
    mode = parse_mode(argc, argv, &start_idx);
    if (!init_data(&data) || !parse_args(argc, argv, start_idx, &data))
    {
        free_all(&data);
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    if (!is_sorted(data.stack_a))
    {
        disorder = compute_disorder(data.stack_a, data.size_a);
        execute_strategy(&data, mode, disorder);
    }
    free_all(&data);
    return (0);
}
