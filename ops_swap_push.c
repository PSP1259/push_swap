/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 09:51:09 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/25 13:05:44 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	if (!data)
		return ;
	if (swap(&data->stack_a) == 1)
		record(data, OP_SA);
}

void	sb(t_data *data)
{
	if (!data)
		return ;
	if (swap(&data->stack_b) == 1)
		record(data, OP_SB);
}

void	ss(t_data *data)
{
	int	a_move;
	int	b_move;

	if (!data)
		return ;
	a_move = swap(&data->stack_a);
	b_move = swap(&data->stack_b);
	if (a_move + b_move == 2)
		record(data, OP_SS);
	else if (a_move == 1)
		record(data, OP_SA);
	else if (b_move == 1)
		record(data, OP_SB);
}

void	pa(t_data *data)
{
	if (!data)
		return ;
	if (push(&data->stack_b, &data->stack_a) == 1)
		record(data, OP_PA);
}

void	pb(t_data *data)
{
	if (!data)
		return ;
	if (push(&data->stack_a, &data->stack_b) == 1)
		record(data, OP_PB);
}
