/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 18:21:19 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/22 13:28:22 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c == 0)
		return (1);
	if (c >= 1 && c <= 127)
		return (1);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	int	result;

	result = ft_isascii(111);
	printf("%i", result);
	return (0);
}
*/
