/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:07:20 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/25 13:08:12 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	if (!data)
		return ;
	if (rotate(&data->stack_a) == 1)
		record(data, OP_RA);
}

void	rb(t_data *data)
{
	if (!data)
		return ;
	if (rotate(&data->stack_b) == 1)
		record(data, OP_RB);
}

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
