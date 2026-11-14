/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 18:25:18 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/13 16:27:46 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Runs one sorting algorithm and saves its name and complexity class
** so --bench can display them.
*/

static void	run_strategy(t_data *data, int mode)
{
	if (mode == MODE_SIMPLE)
	{
		data->strategy = "Simple (selection sort)";
		data->complexity = "O(n^2)";
		sort_simple(data);
	}
	else if (mode == MODE_MEDIUM)
	{
		data->strategy = "Medium (chunk sort)";
		data->complexity = "O(n*sqrt(n))";
		sort_medium(data);
	}
	else
	{
		data->strategy = "Complex (radix sort)";
		data->complexity = "O(n*log(n))";
		sort_complex(data);
	}
}

/*
** Directs the program to the correct algorithm based on data->mode.
** In ADAPTIVE mode, it routes based on the computed disorder metric.
*/

void	execute_strategy(t_data *data, float disorder)
{
	if (data->mode != MODE_ADAPTIVE)
		run_strategy(data, data->mode);
	else if (disorder < 0.2f)
		run_strategy(data, MODE_SIMPLE);
	else if (disorder < 0.5f)
		run_strategy(data, MODE_MEDIUM);
	else
		run_strategy(data, MODE_COMPLEX);
}

/*
** Frees everything, prints "Error" on stderr and returns 1,
** so every failure path in main is a single line.
*/

static int	exit_error(t_data *data)
{
	free_all(data);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

/*
** Main entry point. Initializes data, parses flags and numbers,
** measures the disorder before any move, and routes to the correct
** sorting algorithm. With --bench, prints the metrics on stderr.
*/

int	main(int argc, char **argv)
{
	t_data	data;
	int		start;
	float	disorder;

	if (argc < 2)
		return (0);
	if (!init_data(&data))
		return (exit_error(&data));
	start = parse_flags(argc, argv, &data);
	if (start < 0 || !parse_args(argc, argv, start, &data))
		return (exit_error(&data));
	disorder = compute_disorder(data.stack_a, data.size_a);
	if (!is_sorted(data.stack_a))
	{
		if (!assign_ranks(&data))
			return (exit_error(&data));
		execute_strategy(&data, disorder);
		print_ops(&data);
	}
	if (data.bench && data.size_a > 0)
		print_bench(&data, disorder);
	free_all(&data);
	return (0);
}
