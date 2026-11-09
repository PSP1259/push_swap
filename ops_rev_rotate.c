/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:07:33 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/25 13:17:56 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	if (!data)
		return ;
	if (rev_rotate(&data->stack_a) == 1)
		record(data, OP_RRA);
}

void	rrb(t_data *data)
{
	if (!data)
		return ;
	if (rev_rotate(&data->stack_b) == 1)
		record(data, OP_RRB);
}

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
