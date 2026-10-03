/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 22:26:04 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:56:34 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
		j++;
	s3 = malloc(sizeof(char) * (i + j + 1));
	if (!s3)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		s3[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	return (s3);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	text1[] = "Hola ";
	const char	text2[] = "Malaga";
	char		*result;

	result = ft_strjoin(text1, text2);
	printf("%s", result);
	free(result);
	return (0);
}
*/
