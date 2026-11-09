/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:07:20 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/09 15:35:24 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Executes 'ra' (rotate stack a up by one) and records the move.
void	ra(t_data *data)
{
	if (!data)
		return ;
	if (rotate(&data->stack_a) == 1)
		record(data, OP_RA);
}

// Executes 'rb' (rotate stack b up by one) and records the move.
void	rb(t_data *data)
{
	if (!data)
		return ;
	if (rotate(&data->stack_b) == 1)
		record(data, OP_RB);
}

// Executes 'rr' (rotate both stack a and stack b up simultaneously) and records it.
void	rr(t_data *data)
{
	int	a_move;
	int	b_move;

	if (!data)
		return ;
	a_move = rotate(&data->stack_a);
	b_move = rotate(&data->stack_b);
	if (a_move + b_move == 2)
		record(data, OP_RR);
	else if (a_move == 1)
		record(data, OP_RA);
	else if (b_move == 1)
		record(data, OP_RB);
}
