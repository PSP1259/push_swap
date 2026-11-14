/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:45:01 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/13 16:44:00 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int n)
{
	int	max;
	int	bits;

	max = n - 1;
	bits = 0;
	while ((max >> bits) > 0)
		bits++;
	return (bits);
}

void	sort_complex(t_data *data)
{
	int	n;
	int	max_bits;
	int	bit;
	int	i;

	if (!data || data->size_a < 2)
		return ;
	n = data->size_a;
	max_bits = get_max_bits(n);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < n)
		{
			if (((data->stack_a->value >> bit) & 1) == 0)
				pb(data);
			else
				ra(data);
			i++;
		}
		while (data->size_b > 0)
			pa(data);
		bit++;
	}
}
