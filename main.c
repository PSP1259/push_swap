/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 18:25:18 by pspuhler          #+#    #+#             */
/*   Updated: 2026/11/09 12:44:23 by pspuhler         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	data;

<<<<<<< HEAD
	if (argc < 2)
		return (0);
	if (!init_data(&data))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!parse_args(argc, argv, &data))
	{
		free_all(&data);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	print_stack("a", data.stack_a);
	print_stack("b", data.stack_b);
	free_all(&data);
=======
	int	i;
	long value;

	// 1. S. 20 in PDF: If no argument is given, it stops and displays nothing.

	if (argc == 1)
	{
		return (0);
	}

	// 2. Check if int is valid

	i = 1;

	while (i < argc)
	{

		if (!(ft_syntax_check(argv)))
		{
			write(2, "Error\n", 6);
			return (1);
		}

		value = ft_atol(argv[i]);

		if (value > 2147483647 || value < -2147483648)
		{
			write(2, "Error\n", 6);
			return (1);
		}

		i++;
	}



>>>>>>> origin/main
	return (0);
}
