/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 10:08:25 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/12 10:21:06 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
[xy] -> [xy] -> [xy] -> [NEW] -> [NULL]
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

/*
#include <stdio.h>

int main(void)
{
	t_list	*head;
	t_list	node1;
	t_list	node2;
	t_list	new_node;
	t_list	*tmp;

	// 1. Test with an empty list
	head = NULL;
	node1.content = "First Node (was empty before)";
	node1.next = NULL;

	ft_lstadd_back(&head, &node1);
	printf("Empty list test -> Head points to: %s\n", (char *)head->content);

	// 2. Test with an existing list
	node2.content = "Second Node";
	node2.next = NULL;
	head->next = &node2; // Manually link second node

	new_node.content = "Third Node (Added to back!)";
	new_node.next = NULL;

	// Add to the back
	ft_lstadd_back(&head, &new_node);

	// Print the whole list to verify
	printf("\nFull list after ft_lstadd_back:\n");
	tmp = head;
	while (tmp)
	{
		printf("- %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	return (0);
}
*/
