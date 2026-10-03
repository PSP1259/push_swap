/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 09:38:48 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/12 09:48:23 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
[NEW] -> [xy] -> [xy] -> [xy] -> [NULL]
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>

int main(void)
{
	t_list	*head;
	t_list	node1;
	t_list	node2;
	t_list	node3;

	// Initialize empty list
	head = NULL;

	// Prepare Chain
	node1.content = "First (end)";
	node2.content = "Second (mid)";
	node3.content = "Third (first!)";
	node1.next = NULL;
	node2.next = NULL;
	node3.next = NULL;

	// Add at first position
	ft_lstadd_front(&head, &node1);
	ft_lstadd_front(&head, &node2);
	ft_lstadd_front(&head, &node3);

	// Print the list
	while (head)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
	return (0);
}
*/
