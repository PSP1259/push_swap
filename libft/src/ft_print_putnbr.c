/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 16:26:34 by pspuhler          #+#    #+#             */
/*   Updated: 2026/10/01 12:11:07 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_nbr(long nb)
{
	int		count;
	char	c;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
		count++;
	}
	if (nb >= 10)
		count += ft_put_nbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_print_putnbr(va_list args)
{
	int		count;
	long	nb;

	nb = va_arg(args, int);
	count = 0;
	count += ft_put_nbr(nb);
	return (count);
}
