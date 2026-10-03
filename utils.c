/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls.c      		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:22:09 by pspuhler          #+#    #+#             */
/*   Updated: 2026/10/03 12:29:32 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// turn the input char array in a int
long	ft_atol(char *str)
{
	int		i;
	int		base;
	long	result;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] ==' ')
	{
			i++;
	}
	base = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			base *= -1;
		}
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
	}
	return (result * base);
}
