/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:17:01 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/09 16:28:18 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Rotates the stack up by one position (top element becomes bottom element).
 * Simply moves the head pointer to the next node in the circular list.
 * Returns 1 if rotated, or 0 if the stack has fewer than 2 elements.
 */
int	rotate(t_node **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return (0);
	*stack = (*stack)->next;
	return (1);
}

/*
 * Rotates the stack down by one position (bottom element becomes top element).
 * Simply moves the head pointer to the previous node in the circular list.
 * Returns 1 if rotated, or 0 if the stack has fewer than 2 elements.
 */
int	rev_rotate(t_node **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return (0);
	*stack = (*stack)->prev;
	return (1);
}

/*
 * Swaps the top two numbers of the stack by exchanging their integer values.
 * Returns 1 if swapped, or 0 if the stack has fewer than 2 elements.
 */
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

/*
 * Moves the top node from src_stack to the top of dest_stack.
 * Detaches the top node from src_stack and places it as the new 
 * head of dest_stack.
 * Returns 1 if pushed, or 0 if src_stack is empty.
 */
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
