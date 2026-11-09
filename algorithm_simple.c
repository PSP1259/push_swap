/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:45:46 by pspuhler          #+#    #+#             */
/*   Updated: 2026/11/09 17:37:55 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Searches stack_a for the node with the smallest integer value and returns
 * its 0-based index position starting from the top (head = position 0).
 */
int	get_min_pos(t_node *head)
{
	t_node	*current;
	int		min_val;
	int		min_pos;
	int		pos;

	current = head;
	min_val = head->value;
	min_pos = 0;
	pos = 0;
	while (1)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
		if (current == head)
			break ;
	}
	return (min_pos);
}

/*
 * Rotates stack_a until the smallest element is at the top (position 0).
 * Uses 'ra' if the element is in the top half of the stack, or 'rra' if it
 * sits in the bottom half, always taking the shortest path.
 */
void	move_min_to_top(t_data *data)
{
	int	min_pos;

	min_pos = get_min_pos(data->stack_a);
	if (min_pos <= data->size_a / 2)
	{
		while (min_pos > 0)
		{
			ra(data);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < data->size_a)
		{
			rra(data);
			min_pos++;
		}
	}
}

/*
 * Executes the Simple O(n^2) sorting strategy (Selection / Min-Extraction).
 * Repeatedly brings the smallest value in stack_a to the top and pushes it
 * to stack_b, then pushes all elements back to stack_a in sorted order.
 */
void	sort_simple(t_data *data)
{
	if (!data || data->size_a < 2);
		return ;
	while (data->size_a > 1)
	{
		move_min_to_top(data);
		pb(data);
	}
	while (data->stack_b != NULL)
	{
		pa(data);
	}
}
