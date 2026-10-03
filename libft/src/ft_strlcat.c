/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:21:36 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:56:32 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lens;
	size_t	lend;

	i = 0;
	lens = 0;
	lend = 0;
	while (lend < size && dest[lend] != '\0')
		lend++;
	while (src[lens] != '\0')
		lens++;
	if (size <= lend)
		return (size + lens);
	while ((src[i] != '\0') && (size > (lend + i + 1)))
	{
		dest[lend + i] = src[i];
		i++;
	}
	dest[lend + i] = '\0';
	return (lens + lend);
}

/*
int	main(void)
{
	char	text[50] = "Hola ";
	char	src[50] = "Malaga";
	size_t	result;

	result = ft_strlcat(text, src, 8);
	printf("%s\n\n", text);
	printf("%zu\n", result);
}
*/
