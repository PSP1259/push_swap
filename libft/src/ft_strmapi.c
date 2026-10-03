/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 16:37:01 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:56:24 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
- Line 26: ft_strdup()
- Line 31: ft_strdup()
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*res;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
static char	test(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z' && i % 2 == 0)
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	*res;

	res = ft_strmapi("hola 42", test);
	if (!res)
		return (1);
	printf("%s", res);
	free(res);
	return (0);
}
*/
