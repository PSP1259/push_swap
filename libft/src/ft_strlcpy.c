/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:21:11 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:56:29 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lens;

	i = 0;
	lens = 0;
	while (src[lens] != '\0')
		lens++;
	if (size == 0)
		return (lens);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lens);
}

/*
int	main(void)
{
	char	text[50] = "Hola Malaga";
	char	dest[50];

	ft_strlcpy(dest, text, 15);
	printf("%s", dest);
	return (0);
}
*/
