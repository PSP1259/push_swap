/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:40:18 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 15:48:45 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	del_content(void *content)
{
	free(content);
}
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	lst->next = NULL;
	free(lst);
}

/*
int	main(void)
{
	t_list	*node;
	char	*dynamic_str;

	// 1. Dynamically allocate content so it can actually be freed
	dynamic_str = strdup("Test String");
	if (!dynamic_str)
		return (1);

	// 2. Create the node using your ft_lstnew
	node = ft_lstnew(dynamic_str);
	if (!node)
	{
		free(dynamic_str);
		return (1);
	}

	printf("Node created. Content: %s\n", (char *)node->content);

	// 3. Delete the node and its content
	ft_lstdelone(node, del_content);

	printf("Node and dynamically allocated content successfully freed.\n");

	return (0);
}
*/
