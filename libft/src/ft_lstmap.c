/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:33:56 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:57:08 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
// 1. The 'f' function: Creates a NEW string (uppercase)
void	*map_to_upper(void *content)
{
	char	*str;
	char	*new_str;
	int		i;

	str = (char *)content;
	new_str = strdup(str); // Allocate memory for the new mapped content
	if (!new_str)
		return (NULL);
	i = 0;
	while (new_str[i])
	{
		if (new_str[i] >= 'a' && new_str[i] <= 'z')
			new_str[i] -= 32;
		i++;
	}
	return (new_str);
}

// 2. The 'del' function
void	del_content(void *content)
{
	free(content);
}
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}

/*
int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*mapped_list;
	t_list	*tmp;

	// Setup original list
	node1 = ft_lstnew(strdup("hello"));
	node2 = ft_lstnew(strdup("malaga"));
	node3 = ft_lstnew(strdup("libft"));
	node1->next = node2;
	node2->next = node3;

	// Execute ft_lstmap
	mapped_list = ft_lstmap(node1, map_to_upper, del_content);

	// Print new list
	printf("--- Mapped List ---\n");
	tmp = mapped_list;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	// Clean up both lists to prevent leaks
	ft_lstclear(&node1, del_content);
	ft_lstclear(&mapped_list, del_content);

	return (0);
}
*/
