/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:45:11 by pspuhler          #+#    #+#             */
/*   Updated: 2026/11/10 10:45:39 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Pushes all elements back to stack_a in descending order.
** Always looks for the current maximum value in stack_b.
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
** Pushes elements to stack_b in chunks.
** If the pushed value is in the lower half of the chunk, it is rotated
** to the bottom of stack_b to pre-sort the chunk.
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
		while (pushed < limit && data->size_a > 0)
		{
			if (data->stack_a->index <= limit)
			{
				pb(data);
				pushed++;
				if (data->stack_b->index <= limit - (chunk_size / 2))
					rb(data);
			}
			else
				ra(data);
		}
		i++;
	}
}

/*
** Executes the O(n * sqrt(n)) chunking strategy.
** Assumes elements have been pre-indexed (0 to size-1).
*/
void	sort_medium(t_data *data)
{
	int	chunk_size;
	int	chunks;

	if (data->size_a <= 1)
		return ;
	chunks = 5;
	if (data->size_a < 50)
		chunks = 3;
	chunk_size = data->size_a / chunks;
	if (data->size_a % chunks != 0)
		chunk_size++;
	push_chunks(data, chunk_size, chunks);
	push_back_to_a(data);
}
