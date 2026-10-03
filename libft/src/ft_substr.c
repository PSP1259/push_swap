/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 13:45:55 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:56:17 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
! This version has > 25 lines (norminette fail), work with:
- line 31: ft_strlen(s)
- line 33: ft_sturdup("")
- line 47: ft_strlcpy(res, src, reslen)
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if ((size_t)start >= i)
		len = 0;
	else if (len > i - start)
		len = i - start;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (j < len)
	{
		res[j] = s[start + j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

/*
int	main(void)
{
	char const	text[] = "Hola Malaga";
	char	*result;

	result = ft_substr(text, 5, 12);
	printf("%s", result);
	free(result);
	return (0);
}
*/
