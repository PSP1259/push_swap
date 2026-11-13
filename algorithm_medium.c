/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:45:11 by pspuhler          #+#    #+#             */
/*   Updated: 2026/11/13 11:30:12 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Computes the integer square root of n to scale chunk count by O(sqrt(n)).
 */
static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

/*
 * Assigns each node in stack_a its sorted rank (0 to size_a - 1) in node->index
 * by counting how many other nodes in the stack have a strictly smaller value.
 */
static void	init_indices(t_data *data)
{
	t_node	*outer;
	t_node	*inner;
	int		rank;
	int		i;
	int		j;

	outer = data->stack_a;
	i = 0;
	while (i < data->size_a)
	{
		rank = 0;
		inner = data->stack_a;
		j = 0;
		while (j < data->size_a)
		{
			if (inner->value < outer->value)
				rank++;
			inner = inner->next;
			j++;
		}
		outer->index = rank;
		outer = outer->next;
		i++;
	}
}

/*
 * Pushes all elements from stack_b back to stack_a from largest to smallest.
 * Rotates via rb or rrb depending on whether the max element is in the top
 * or bottom half of stack_b.
 */
static void	push_back_to_a(t_data *data)
{
	int	max_val;
	int	max_pos;

	while (data->size_b > 0)
	{
		max_val = get_max_val(data->stack_b);
		max_pos = get_node_pos(data->stack_b, max_val);
		if (max_pos <= data->size_b / 2)
		{
			while (data->stack_b->value != max_val)
				rb(data);
		}
		else
		{
			while (data->stack_b->value != max_val)
				rrb(data);
		}
		pa(data);
	}
}

/*
 * Pushes elements from stack_a to stack_b chunk by chunk.
 * Rotates elements in the lower half of the current chunk to the bottom of
 * stack_b (rb) to create an hourglass pre-sort distribution.
 */
static void	push_chunks(t_data *data, int chunk_size, int chunks)
{
	int	i;
	int	limit;
	int	pushed;

	i = 1;
	pushed = 0;
	while (i <= chunks && data->size_a > 0)
	{
		limit = i * chunk_size;
		if (i == chunks)
			limit = data->size_a + data->size_b;
		while (pushed < limit && data->size_a > 0)
		{
			if (data->stack_a->index < limit)
			{
				pb(data);
				pushed++;
				if (data->stack_b->index < limit - (chunk_size / 2))
					rb(data);
			}
			else
				ra(data);
		}
		i++;
	}
}

/*
 * Executes the Medium O(n * sqrt(n)) chunk-based sorting strategy.
 * Scales chunk count proportionally to sqrt(n) for optimal performance.
 */
void	sort_medium(t_data *data)
{
	int	chunk_size;
	int	chunks;

	if (!data || data->size_a <= 1)
		return ;
	init_indices(data);
	chunks = ft_sqrt(data->size_a) / 2;
	if (chunks < 1)
		chunks = 1;
	chunk_size = data->size_a / chunks;
	if (data->size_a % chunks != 0)
		chunk_size++;
	push_chunks(data, chunk_size, chunks);
	push_back_to_a(data);
}
