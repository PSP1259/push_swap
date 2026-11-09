/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:17:01 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/25 12:35:59 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_node **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return (0);
	*stack = (*stack)->next;
	return (1);
}

int	rev_rotate(t_node **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return (0);
	*stack = (*stack)->prev;
	return (1);
}

int	swap(t_node **stack)
{
	int	temp;

	if (!stack || !*stack || (*stack)->next == *stack)
		return (0);
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
	return (1);
}

int	push(t_node **src_stack, t_node **dest_stack)
{
	t_node	*src_head;

	if (!src_stack || !*src_stack || !dest_stack)
		return (0);
	src_head = *src_stack;
	if ((*src_stack)->next == *src_stack)
		*src_stack = NULL;
	else
	{
		src_head->prev->next = src_head->next;
		src_head->next->prev = src_head->prev;
		*src_stack = src_head->next;
	}
	ft_add_node_back(dest_stack, src_head);
	*dest_stack = src_head;
	return (1);
}
