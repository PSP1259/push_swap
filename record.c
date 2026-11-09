/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 13:24:24 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/09 15:50:07 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Initializes the main t_data structure before parsing begins.
 * Sets stack_a and stack_b to empty (NULL) and allocates memory for
 * recording up to 1024 operations initially. Returns 1 on success, 0 on error.
 */
int	init_data(t_data *data)
{
	if (!data)
		return (0);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->capacity = 1024;
	data->n_ops = 0;
	data->ops = malloc(sizeof(t_op) * data->capacity);
	if (!data->ops)
		return (0);
	return (1);
}

/*
 * Saves an executed operation into the dynamic ops array.
 * If the array is full (n_ops == capacity), it doubles the allocated memory
 * so no operations are ever lost. Returns 1 on success, 0 on malloc error.
 */
int	record(t_data *data, t_op op)
{
	t_op	*new_ops;

	if (data->n_ops == data->capacity)
	{
		new_ops = malloc(sizeof(t_op) * (data->capacity * 2));
		if (!new_ops)
			return (0);
		ft_memcpy(new_ops, data->ops, data->capacity * sizeof(t_op));
		free(data->ops);
		data->ops = new_ops;
		data->capacity = data->capacity * 2;
	}
	data->ops[data->n_ops] = op;
	data->n_ops++;
	return (1);
}

/*
 * Prints all recorded operations as text ("sa", "pb", etc.) to standard output,
 * separated by newlines, matching the exact order they were executed.
 */
void	print_ops(t_data *data)
{
	static char	*table[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	int			i;

	if (!data)
		return ;
	i = 0;
	while (i < data->n_ops)
	{
		ft_putendl_fd(table[data->ops[i]], 1);
		i++;
	}
}

/*
 * Cleans up all dynamically allocated memory (stack_a, stack_b, and ops array)
 * before the program exits to prevent memory leaks.
 */
void	free_all(t_data *data)
{
	if (!data)
		return ;
	free_list(&data->stack_a);
	free_list(&data->stack_b);
	free(data->ops);
	data->ops = NULL;
	data->n_ops = 0;
	data->capacity = 0;
}
