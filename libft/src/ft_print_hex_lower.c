/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 23:07:49 by pspuhler          #+#    #+#             */
/*   Updated: 2026/10/01 12:11:11 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex_lower(unsigned int n)
{
	int		count;
	char	*hex;
	char	c;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_put_hex_lower(n / 16);
	c = hex[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_print_hex_lower(va_list args)
{
	int				count;
	unsigned int	n;

	n = va_arg(args, unsigned int);
	count = ft_put_hex_lower(n);
	return (count);
}
