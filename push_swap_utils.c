/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:15:17 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/13 16:49:24 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	t_node	*head;

	head = stack;
	if (stack == NULL || stack->next == stack)
		return (1);
	while (stack->next != head)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
*	Returns the biggest value in the stack.
*	Walks the whole circle once, starting at the head.
*	Returns 0 for an empty stack (callers should check the size first).
*/
int	get_max_val(t_node *stack)
{
	t_node	*current;
	int		max;

	if (!stack)
		return (0);
	max = stack->value;
	current = stack->next;
	while (current != stack)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

/*
*	Returns the position of 'value' in the stack, counting from the
*	top (head = 0). Returns -1 if the stack is empty or the value
*	isn't in it.
*/
int	get_node_pos(t_node *stack, int value)
{
	t_node	*current;
	int		pos;

	if (!stack)
		return (-1);
	current = stack;
	pos = 0;
	while (1)
	{
		if (current->value == value)
			return (pos);
		current = current->next;
		pos++;
		if (current == stack)
			break ;
	}
	return (-1);
}
