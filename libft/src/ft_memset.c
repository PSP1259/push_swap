/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 18:41:08 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:56:54 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;

	p = (unsigned char *)s;
	ch = c;
	while (n > 0)
	{
		*p = ch;
		p++;
		n--;
	}
	return (s);
}

/*
#include <stdio.h>

int main(void)
{
	char	text[50] = "Hola Malaga";

	printf("Before: %s\n", text);
	ft_memset(text, 'X', 5);
	printf("After: %s\n\n", text);

	int	zahlen[5];

	ft_memset(zahlen, 0, sizeof(zahlen));
	printf("First: %d\n", zahlen[0]);
	printf("Last: %d\n", zahlen[4]);

	return (0);
}
*/
