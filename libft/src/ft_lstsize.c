/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 09:54:03 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/22 15:46:23 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
#include <stdio.h>

int main(void)
{
	t_list	node1;
	t_list	node2;
	t_list	node3;

	// Setup nodes and link them together
	node1.content = "Node 1";
	node1.next = &node2;

	node2.content = "Node 2";
	node2.next = &node3;

	node3.content = "Node 3";
	node3.next = NULL;

	// Test 1: Normal list
	printf("Expected size: 3 | Actual size: %u\n", ft_lstsize(&node1));

	// Test 2: Empty list (NULL)
	printf("Expected size: 0 | Actual size: %u\n", ft_lstsize(NULL));

	return (0);
}
*/
