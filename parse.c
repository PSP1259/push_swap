/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 16:14:22 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/10 11:20:34 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Turns a string to a integer.
 * Checks if the input is a digit.
 */
int	ft_atoi_safe(const char *str, int *out)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_isdigit(str[i]) == 0)
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		result = result * 10 + (str[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		i++;
	}
	*out = result * sign;
	return (1);
}

/*
 * Compares every node in stack_a with all subsequent nodes to detect
 * duplicate numbers. Returns 1 if a duplicate is found, or 0 if all are unique.
 */
int	duplicate_checker(t_node *head)
{
	t_node	*outer;
	t_node	*inner;

	if (!head)
		return (0);
	outer = head;
	while (outer->next != head)
	{
		inner = outer->next;
		while (inner != head)
		{
			if (inner->value == outer->value)
				return (1);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0);
}

/*
 * Loops through all command-line arguments starting at index 1.
 * Converts each string to an integer via ft_atoi_safe, creates a new node,
 * appends it to stack_a, and checks for duplicates at the end.
 * Returns 1 if all inputs are valid, or 0 on any error.
 */
int	parse_args(int argc, char **argv, t_data *data)
{
	int		i;
	int		num;
	t_node	*node;

	if (!data)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (ft_atoi_safe(argv[i], &num) == 0)
			return (0);
		node = ft_create_node(num);
		if (!node)
			return (0);
		data->size_a++;
		ft_add_node_back(&data->stack_a, node);
		i++;
	}
	if (duplicate_checker(data->stack_a) == 1)
		return (0);
	return (1);
}

/*
*	Counts how many values in the stack are smaller than 'value'.
*	That count is the rank of 'value': the smallest gets 0,
*	the biggest gets size - 1.
*	Walks exactly 'size' nodes, because the list is circular
*	and has no NULL at the end.
*/
int	count_smaller(t_node *stack, int value, int size)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (i < size)
	{
		if (stack->value < value)
			counter++;
		i++;
		stack = stack->next;
	}
	return (counter);
}

/*
*	Replaces every value in stack a with its rank (0 to size_a - 1),
*	keeping the order of the stack the same.
*	Uses a temporary array so all ranks are computed from the
*	original values before any node is overwritten.
*	Returns 1 on success, 0 if malloc fails.
*/
int	assign_ranks(t_data *data)
{
	int	*ranks;
	t_node	*current;
	int i;

	i = 0;
	current = data->stack_a;
	ranks = malloc(sizeof(int) * data->size_a);
	if (!ranks)
		return (0);
	while (i < data->size_a)
	{
		ranks[i] = count_smaller(data->stack_a, current->value, data->size_a);
		current = current->next;
		i++;
	}
	current = data->stack_a;
	i = 0;
	while (i < data->size_a)
	{
		current->value = ranks[i];
		current = current->next;
		i++;
	}
	free(ranks);
	return(1);
}
