/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 13:06:13 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:56:39 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Without strlcpy (line 32)

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] != '\0')
		len++;
	len++;
	d = malloc(len * sizeof(char));
	if (!d)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/*
int	main(void)
{
	const char	text[] = "Hola Malaga";
	char	*result;

	result = ft_strdup(text);
	printf("%s", result);
	free(result);
	return (0);
}
*/
