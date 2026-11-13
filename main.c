/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 18:25:18 by pspuhler          #+#    #+#             */
/*   Updated: 2026/11/13 13:15:37 by juan-jos         ###   ########.fr       */
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
** Directs the program to the correct algorithm based on data->mode.
** In ADAPTIVE mode, it routes based on the computed disorder metric.
*/
void	execute_strategy(t_data *data, float disorder)
{
	if (data->mode == MODE_SIMPLE)
		sort_simple(data);
	else if (data->mode == MODE_MEDIUM)
		sort_medium(data);
	else if (data->mode == MODE_COMPLEX)
		sort_complex(data);
	else if (data->mode == MODE_ADAPTIVE)
	{
		if (disorder < 0.2f)
			sort_simple(data);
		else if (disorder < 0.5f)
			sort_medium(data);
		else
			sort_complex(data);
	}
}

/*
** Frees everything, prints "Error" on stderr and returns 1,
** so every failure path in main is a single line.
*/
static int	exit_error(t_data *data)
{
	free_all(data);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

/*
** Main entry point. Initializes data, parses flags and numbers,
** and routes to the correct sorting algorithm.
*/
int	main(int argc, char **argv)
{
	t_data	data;
	int		start;

	if (argc < 2)
		return (0);
	if (!init_data(&data))
		return (exit_error(&data));
	start = parse_flags(argc, argv, &data);
	if (start < 0)
		return (exit_error(&data));
	if (start >= argc)
	{
		free_all(&data);
		return (0);
	}
	if (!parse_args(argc, argv, start, &data))
		return (exit_error(&data));
	if (!is_sorted(data.stack_a))
	{
		if (!assign_ranks(&data))
			return (exit_error(&data));
		execute_strategy(&data, compute_disorder(data.stack_a, data.size_a));
		print_ops(&data);
	}
	free_all(&data);
	return (0);
}