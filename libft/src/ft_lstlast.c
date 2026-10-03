/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 10:03:20 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/12 10:07:09 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
[xy] -> [xy] -> [xy] -> [LAST] -> [NULL]
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
#include <stdio.h>

int main(void)
{
	t_list	node1;
	t_list	node2;
	t_list	node3;
	t_list	*last;

	// Setup nodes
	node1.content = "First Node";
	node1.next = &node2;

	node2.content = "Second Node";
	node2.next = &node3;

	node3.content = "Third Node (Target)";
	node3.next = NULL;

	// Test 1: Normal list
	last = ft_lstlast(&node1);
	if (last)
		printf("Last node contains: %s\n", (char *)last->content);

	// Test 2: Empty list (NULL)
	last = ft_lstlast(NULL);
	if (!last)
		printf("NULL test passed successfully.\n");

	return (0);
}
*/
