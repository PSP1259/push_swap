/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:28:04 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/13 16:51:39 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* Prints the disorder (0.0 - 1.0) as a percentage with two decimals.
* Example: 0.4567 -> "45.67%".
*/
static void	put_percent(float disorder)
{
	int	hundredths;

	hundredths = (int)(disorder * 10000.0f + 0.5f);
	ft_putnbr_fd(hundredths / 100, 2);
	ft_putchar_fd('.', 2);
	if (hundredths % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(hundredths % 100, 2);
	ft_putstr_fd("%\n", 2);
}

/*
* Prints one "[bench] label: n" line on stderr.
*/
static void	put_count(char *label, int n)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd(label, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(n, 2);
	ft_putchar_fd('\n', 2);
}

/*
* Counts how many times each operation was used and prints one line
* per operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).
*/
static void	put_op_counts(t_data *data)
{
	static char	*names[] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};
	int			count[11];
	int			i;

	ft_bzero(count, sizeof(count));
	i = 0;
	while (i < data->n_ops)
	{
		count[data->ops[i]]++;
		i++;
	}
	i = 0;
	while (i < 11)
	{
		put_count(names[i], count[i]);
		i++;
	}
}

/*
* Benchmark mode (--bench): prints on stderr the disorder, the strategy
* used with its complexity class, the total number of operations and
* how many times each operation was used.
*/
void	print_bench(t_data *data, float disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	put_percent(disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	if (data->mode == MODE_ADAPTIVE)
		ft_putstr_fd("Adaptive -> ", 2);
	ft_putstr_fd((char *) data->strategy, 2);
	ft_putstr_fd(" ", 2);
	ft_putendl_fd((char *) data->complexity, 2);
	put_count("total_ops", data->n_ops);
	put_op_counts(data);
}
