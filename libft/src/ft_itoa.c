/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:18:14 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:57:17 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*str;

	nbr = n;
	len = ft_len(nbr);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		len--;
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *str;

	str = ft_itoa(42);
	printf("Test 42: %s\n", str);
	free(str);

	str = ft_itoa(-42);
	printf("Test -42: %s\n", str);
	free(str);

	str = ft_itoa(0);
	printf("Test 0: %s\n", str);
	free(str);

	str = ft_itoa(INT_MIN);
	printf("Test INT_MIN: %s\n", str);
	free(str);

	str = ft_itoa(INT_MAX);
	printf("Test INT_MAX: %s\n", str);
	free(str);

	return (0);
}
*/
