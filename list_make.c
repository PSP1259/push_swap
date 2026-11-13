/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_make.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:19:31 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/13 11:28:43 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Allocates and initializes a new stack node with the given integer value.
 * Sets next and prev pointers to NULL and returns the node (or NULL on error).
 */
t_node	*ft_create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/*
 * Appends a new node to the end of the circular doubly linked list.
 * If the stack is empty (*lst == NULL), the single node points to itself.
 * Otherwise, links the new node between the current
 * last node and the first node.
 */
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

/*
 * TEST ONLY: Prints all values in the circular list from top to bottom.
 * (Must be removed or replaced before final submission due to printf).
 */
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

/*
 * Frees all allocated nodes in a stack and resets the stack pointer to NULL.
 * Breaks the circular loop first so the while-loop terminates cleanly.
 */
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
