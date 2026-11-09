/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 09:51:09 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/09 16:13:18 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Executes 'sa' (swap top two elements of stack a) and records the move.
void	sa(t_data *data)
{
	if (!data)
		return ;
	if (swap(&data->stack_a) == 1)
		record(data, OP_SA);
}

// Executes 'sb' (swap top two elements of stack b) and records the move.
void	sb(t_data *data)
{
	if (!data)
		return ;
	if (swap(&data->stack_b) == 1)
		record(data, OP_SB);
}

// Executes 'ss' (swap both stack a and stack b simultaneously) and records it.
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

/*  
*	Executes 'pa' (push top of stack b to top of stack a) and records the move.
*	Also modifies the size so it saves the current size of the stack
*/
void	pa(t_data *data)
{
	if (!data)
		return ;
	if (push(&data->stack_b, &data->stack_a) == 1)
	{
		data->size_a++;
		data->size_b--;
		record(data, OP_PA);
	}
}

/* 
*	Executes 'pb' (push top of stack a to top of stack b) and records the move.
*	Also modifies the size so it saves the current size of the stack
*/
void	pb(t_data *data)
{
	if (!data)
		return ;
	if (push(&data->stack_a, &data->stack_b) == 1)
	{
		data->size_a--;
		data->size_b++;
		record(data, OP_PB);
	}
}
