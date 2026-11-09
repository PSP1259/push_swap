/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_make.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:19:31 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/21 18:17:28 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_add_node_back(t_node **lst, t_node *new)
{
	t_node	*node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		new->next = new;
		new->prev = new;
		*lst = new;
		return ;
	}
	node = (*lst)->prev;
	new->prev = node;
	new->next = *lst;
	node->next = new;
	(*lst)->prev = new;
}

void	print_list(t_node *head)
{
	t_node	*current;

	if (!head)
		return ;
	current = head;
	while (current)
	{
		printf("%d", current->value);
		printf("\n");
		current = current->next;
		if (current == head)
			break ;
	}
}

void	free_list(t_node **head)
{
	t_node	*temp;
	t_node	*next_node;

	if (!head || !*head)
		return ;
	(*head)->prev->next = NULL;
	temp = *head;
	while (temp != NULL)
	{
		next_node = temp->next;
		free(temp);
		temp = next_node;
	}
	*head = NULL;
}
