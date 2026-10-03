/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:42:37 by pspuhler          #+#    #+#             */
/*   Updated: 2026/10/01 12:11:02 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(va_list args);
int	ft_print_str(va_list args);
int	ft_print_ptr(va_list args);
int	ft_print_putnbr(va_list args);
int	ft_print_unsigned(va_list args);
int	ft_print_hex_lower(va_list args);
int	ft_print_hex_upper(va_list args);
int	ft_print_percent(void);

#endif
