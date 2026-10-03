/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 12:30:49 by pspuhler          #+#    #+#             */
/*   Updated: 2026/10/01 12:11:08 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(unsigned long long n)
{
	int		count;
	char	*hex;
	char	c;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_put_hex(n / 16);
	c = hex[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_print_ptr(va_list args)
{
	int					count;
	void				*ptr;
	unsigned long long	forhex;

	ptr = va_arg(args, void *);
	count = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count += 2;
	forhex = (unsigned long long)ptr;
	count += ft_put_hex(forhex);
	return (count);
}
