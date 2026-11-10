/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:18:23 by pspuhler          #+#    #+#             */
/*   Updated: 2026/11/10 10:20:42 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* Helper function to count how many subsequent numbers are smaller
* than the current node's value.
*/
static int	count_mistakes(t_node *current_i, int j, int size)
{
	t_node	*current_j;
	int		mistakes;

	mistakes = 0;
	current_j = current_i->next;
	while (j < size)
	{
		if (current_i->value > current_j->value)
			mistakes++;
		current_j = current_j->next;
		j++;
	}
	return (mistakes);
}

/*
** Calculates the disorder metric (0.0 = perfectly sorted, 1.0 = unsorted).
** Uses the mathematical formula (n * (n - 1)) / 2 for total pairs.
*/
float	compute_disorder(t_node *head, int size)
{
	int		mistakes;
	int		total_pairs;
	int		i;
	t_node	*current_i;

	if (!head || size < 2)
		return (0.0f);
	mistakes = 0;
	total_pairs = (size * (size - 1)) / 2;
	current_i = head;
	i = 0;
	while (i < size - 1)
	{
		mistakes += count_mistakes(current_i, i + 1, size);
		current_i = current_i->next;
		i++;
	}
	return ((float)mistakes / (float)total_pairs);
}
