/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:57:36 by pspuhler          #+#    #+#             */
/*   Updated: 2026/10/01 12:11:10 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex_upper(unsigned int n)
{
	int		count;
	char	*hex;
	char	c;

	hex = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_put_hex_upper(n / 16);
	c = hex[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_print_hex_upper(va_list args)
{
	int				count;
	unsigned int	n;

	n = va_arg(args, unsigned int);
	count = ft_put_hex_upper(n);
	return (count);
}
