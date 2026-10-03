/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 17:04:08 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:56:37 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
static void	my_upper(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z' && i % 2 == 0)
		*c -= 32;
}

int	main(void)
{
	char	str[] = "Hola Malaga";

	ft_striteri(str, my_upper);
	printf("%s", str);
	return (0);
}
*/
