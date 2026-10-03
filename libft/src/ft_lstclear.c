/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 10:33:52 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:57:15 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	del_content(void *content)
{
	free(content);
}
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

/*
int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	// 1. Allocate dynamic content and create nodes
	node1 = ft_lstnew(strdup("First Node"));
	node2 = ft_lstnew(strdup("Second Node"));
	node3 = ft_lstnew(strdup("Third Node"));

	// Protect against malloc fails in the test
	if (!node1 || !node2 || !node3)
		return (1);

	// 2. Link them together
	node1->next = node2;
	node2->next = node3;
	head = node1; // Head points to the first node

	printf("List created. Clearing it now...\n");

	// 3. Clear the entire list
	ft_lstclear(&head, del_content);

	// 4. Verify that the head pointer was set to NULL
	if (head == NULL)
		printf("Success! The list was cleared and head is now NULL.\n");
	else
		printf("Error: Head is not NULL.\n");

	return (0);
}
*/
