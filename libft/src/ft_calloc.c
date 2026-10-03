/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 12:24:40 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/25 12:24:46 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*r;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	r = malloc(nmemb * size);
	if (!r)
		return (NULL);
	ft_bzero(r, nmemb * size);
	return (r);
}

/*
int	main(void)
{
	char	*result;

	result = ft_calloc(5, 1);
	result[0] = 'A';
	result[1] = 'B';
	printf("%s", result);
	free(result);
	return (0);
}
*/
