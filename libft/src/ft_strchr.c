/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:38:00 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/25 17:38:05 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = c;
	while (*s != '\0')
	{
		if (*s == cc)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == cc)
		return ((char *)s);
	return (0);
}

/*
#include <stdio.h>

int main(void)
{
	const char	*str = "Hola Malaga";
	char		*result;

	result = ft_strchr(str, 'a');
	printf("Test 1 (search 'a'):\n");
	if (result)
		printf("Found: %s\n\n", result);
	else
		printf("Not found!\n\n");

	result = ft_strchr(str, 'z');
	printf("Test 2 (search 'z'):\n");
	if (result)
		printf("Found: %s\n\n", result);
	else
		printf("Not found!\n\n");

	result = ft_strchr(str, '\0');
	printf("Test 3 (search '\\0'):\n");
	if (result)
		printf("Found Null-Byte %ld\n", result - str);
	else
		printf("Not found!\n");

	return (0);
}
*/
