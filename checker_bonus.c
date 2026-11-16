/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:24:24 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/16 15:52:02 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	exec_op(t_data *data, t_op op)
{
	if (op == OP_SA)
		sa(data);
	else if (op == OP_SB)
		sb(data);
	else if (op == OP_SS)
		ss(data);
	else if (op == OP_PA)
		pa(data);
	else if (op == OP_PB)
		pb(data);
	else if (op == OP_RA)
		ra(data);
	else if (op == OP_RB)
		rb(data);
	else if (op == OP_RR)
		rr(data);
	else if (op == OP_RRA)
		rra(data);
	else if (op == OP_RRB)
		rrb(data);
	else if (op == OP_RRR)
		rrr(data);
}

static void	run_stored_ops(t_data *data)
{
	int	total;
	int	i;

	total = data->n_ops;
	i = 0;
	while (i < total)
	{
		exec_op(data, data->ops[i]);
		i++;
	}
}
static int	exit_error(t_data *data)
{
	free_all(data);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	if (!init_data(&data) || !parse_args(argc, argv, 1, &data))
		return (exit_error(&data));
	if (!read_instructions(&data))
		return (exit_error(&data));
	run_stored_ops(&data);
	if (is_sorted(data.stack_a) && data.size_b == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_all(&data);
	return (0);
}