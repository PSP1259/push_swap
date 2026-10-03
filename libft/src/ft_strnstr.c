/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:12:22 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/13 11:46:28 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ib;
	size_t	il;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	ib = 0;
	while (ib < len && big[ib] != '\0')
	{
		il = 0;
		while (big[ib + il] != '\0' && little[il] != '\0'
			&& ib + il < len && big[ib + il] == little[il])
		{
			il++;
		}
		if (little[il] == '\0')
			return ((char *)&big[ib]);
		ib++;
	}
	return (0);
}

/*
#include <stdio.h>

int main(void)
{
	const char	big[] = "Hola Malaga";
	const char	little [] = "al";
	const char	*result;

	result = ft_strnstr(big, little, 13);
	printf("%s", result);
	return (0);
}
*/
