/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 19:35:16 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:58:29 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
-> Without libft.h library:

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

/*
int	main(void)
{
	char	*str = "Hola Malaga";
	t_list	*result;

	result = ft_lstnew(str);
	if (result)
	{
		printf("Content: %s\n", (char *)result->content);
		free(result);
	}
	return (0);
}
*/
