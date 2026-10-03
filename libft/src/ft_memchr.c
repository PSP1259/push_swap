/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 13:06:22 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:57:03 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		ch;
	size_t				i;

	p = (const unsigned char *)s;
	ch = c;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*p == ch)
		{
			return ((void *)p);
		}
		p++;
		i++;
	}
	return (0);
}

/*
int main(void)
{
    char        str[] = "Hola, 42 Malaga!";
    char        *found;

    printf("--- Test 1: Standard Search ---\n");
    found = ft_memchr(str, 'M', sizeof(str));
    printf("Found: '%c'", *found);


    printf("\n--- Test 2: Character Not Present ---\n");
    found = ft_memchr(str, 'z', sizeof(str));
	if (!found)
    	printf("Character 'z' correctly not found.\n");
	else
		printf("ERROR");


    printf("\n--- Test 3: Memory with Null Bytes ---\n");
    char        data[] = { 'A', 'B', '\0', 'C', 'D' };

    found = ft_memchr(data, 'C', 3);
	if (!found)
    	printf("With n = 3: 'C' not found as expected (n too small).\n");
	else
		printf("ERROR");


    return (0);
}
*/
