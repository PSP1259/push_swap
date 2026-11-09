/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:07:33 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/09 15:35:55 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Executes 'rra' (reverse rotate stack a down by one) and records the move.
void	rra(t_data *data)
{
	if (!data)
		return ;
	if (rev_rotate(&data->stack_a) == 1)
		record(data, OP_RRA);
}

// Executes 'rrb' (reverse rotate stack b down by one) and records the move.
void	rrb(t_data *data)
{
	if (!data)
		return ;
	if (rev_rotate(&data->stack_b) == 1)
		record(data, OP_RRB);
}

// Executes 'rrr' (reverse rotate both stacks down simultaneously) and records it.
void	rrr(t_data *data)
{
	int	a_move;
	int	b_move;

	if (!data)
		return ;
	a_move = rev_rotate(&data->stack_a);
	b_move = rev_rotate(&data->stack_b);
	if (a_move + b_move == 2)
		record(data, OP_RRR);
	else if (a_move == 1)
		record(data, OP_RRA);
	else if (b_move == 1)
		record(data, OP_RRB);
}
