/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:04:59 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/19 13:06:02 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Sorts 2 elements: swaps them if the top one is bigger.
 */
static void	sort_two(t_data *data)
{
	if (data->stack_a->value > data->stack_a->next->value)
		sa(data);
}

/*
 * Sorts 3 elements in at most 2 moves.
 * First sends the biggest to the bottom (ra if it's on top, rra if it's
 * in the middle), then swaps the top two if they are still out of order.
 */
static void	sort_three(t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	top = data->stack_a->value;
	mid = data->stack_a->next->value;
	bot = data->stack_a->prev->value;
	if (top > mid && top > bot)
		ra(data);
	else if (mid > top && mid > bot)
		rra(data);
	if (data->stack_a->value > data->stack_a->next->value)
		sa(data);
}

/*
 * Sorts 4 or 5 elements: pushes the smallest ones to b until 3 remain
 * (or a is already sorted), sorts those 3, then pushes everything back.
 * The pushed values are the smallest, with the larger of them on top
 * of b, so pushing back keeps a in order.
 */
static void	sort_five(t_data *data)
{
	while (data->size_a > 3 && !is_sorted(data->stack_a))
	{
		move_min_to_top(data);
		pb(data);
	}
	if (data->size_a == 3)
		sort_three(data);
	while (data->size_b > 0)
		pa(data);
}

/*
 * Entry point for inputs of 2 to 5 numbers.
 */
void	sort_small(t_data *data)
{
	if (!data || data->size_a < 2)
		return ;
	if (data->size_a == 2)
		sort_two(data);
	else if (data->size_a == 3)
		sort_three(data);
	else
		sort_five(data);
}