/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 12:25:23 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/25 12:25:27 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*p;
	unsigned char	ch;
	size_t			len;

	len = 0;
	while (s[len] != '\0')
		len++;
	ch = c;
	p = (char *)s + len;
	if (ch == '\0')
	{
		return (p);
	}
	while (p >= s)
	{
		if (*p == ch)
		{
			return (p);
		}
		p--;
	}
	p = NULL;
	return (0);
}

/*
int	main(void)
{
	const char	text[50] = "Hola Malaga";
	char	*result;

	result = ft_strrchr(text, 'l');
	printf("%s", result);
	return (0);
}
*/
