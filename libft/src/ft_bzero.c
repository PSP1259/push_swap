/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:33:35 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:57:22 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	char	text[50] = "Hola Malaga";

	printf("Before: %s\n", text);
	ft_bzero(text, 1);
	printf("After: %s\n", &text[1]);
	return (0);
}
*/
