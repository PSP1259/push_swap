/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:30:02 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/13 16:48:34 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Counts how many values in the stack are smaller than 'value'.
*	That count is the rank of 'value': the smallest gets 0,
*	the biggest gets size - 1.
*	Walks exactly 'size' nodes, because the list is circular
*	and has no NULL at the end.
*/

int	count_smaller(t_node *stack, int value, int size)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (i < size)
	{
		if (stack->value < value)
			counter++;
		i++;
		stack = stack->next;
	}
	return (counter);
}

/*
*	Replaces every value in stack a with its rank (0 to size_a - 1),
*	keeping the order of the stack the same.
*	Uses a temporary array so all ranks are computed from the
*	original values before any node is overwritten.
*	Returns 1 on success, 0 if malloc fails.
*/

int	assign_ranks(t_data *data)
{
	int		*ranks;
	t_node	*current;
	int		i;

	i = 0;
	current = data->stack_a;
	ranks = malloc(sizeof(int) * data->size_a);
	if (!ranks)
		return (0);
	while (i < data->size_a)
	{
		ranks[i] = count_smaller(data->stack_a, current->value, data->size_a);
		current = current->next;
		i++;
	}
	current = data->stack_a;
	i = 0;
	while (i < data->size_a)
	{
		current->value = ranks[i];
		current = current->next;
		i++;
	}
	free(ranks);
	return (1);
}
