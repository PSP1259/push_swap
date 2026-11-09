/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 13:24:24 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/25 11:43:05 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_data(t_data *data)
{
	if (!data)
		return (0);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->capacity = 1024;
	data->n_ops = 0;
	data->ops = malloc(sizeof(t_op)*data->capacity);
	if (!data->ops)
		return (0);
	return (1);
}

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

void	print_ops(t_data *data)
{
	static char *table[] = {"sa","sb","ss","pa","pb","ra","rb",
							"rr","rra","rrb","rrr"};
	int i;
	
	if (!data)
		return ;
	i = 0;
	while (i < data->n_ops)
	{
		ft_putendl_fd(table[data->ops[i]], 1);
		i++;
	}
}

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