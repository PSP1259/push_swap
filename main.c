/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:17:19 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/26 18:03:13 by vboxuser         ###   ########.fr       */
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
	return (0);
}
