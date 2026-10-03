/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:34:06 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:57:10 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	print_content(void *content)
{
	if (content)
		printf("Node content: %s\n", (char *)content);
}
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
int	main(void)
{
	t_list	node1;
	t_list	node2;
	t_list	node3;

	// Setup nodes and link them together
	node1.content = "First Node";
	node1.next = &node2;

	node2.content = "Second Node";
	node2.next = &node3;

	node3.content = "Third Node";
	node3.next = NULL;

	// Iterate through the list and apply the print function
	printf("Testing ft_lstiter:\n");
	ft_lstiter(&node1, print_content);

	return (0);
}
*/
