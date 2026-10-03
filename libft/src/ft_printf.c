/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:43:03 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/25 17:59:39 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(args);
	else if (specifier == 's')
		count += ft_print_str(args);
	else if (specifier == 'p')
		count += ft_print_ptr(args);
	else if (specifier == 'i' || specifier == 'd')
		count += ft_print_putnbr(args);
	else if (specifier == 'u')
		count += ft_print_unsigned(args);
	else if (specifier == 'x')
		count += ft_print_hex_lower(args);
	else if (specifier == 'X')
		count += ft_print_hex_upper(args);
	else if (specifier == '%')
		count += ft_print_percent();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_eval_format(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
