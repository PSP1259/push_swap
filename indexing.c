/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:49:14 by pspuhler          #+#    #+#             */
/*   Updated: 2026/11/10 10:49:16 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Assigns a rank (0 to size-1) to each node based on its integer value.
** This allows sorting algorithms to work with continuous indices.
*/
void	index_stack(t_node *head)
{
	t_node	*curr;
	t_node	*cmp;
	int		rank;

	if (!head)
		return ;
	curr = head;
	while (1)
	{
		rank = 0;
		cmp = head;
		while (1)
		{
			if (cmp->value < curr->value)
				rank++;
			cmp = cmp->next;
			if (cmp == head)
				break ;
		}
		curr->index = rank;
		curr = curr->next;
		if (curr == head)
			break ;
	}
}
