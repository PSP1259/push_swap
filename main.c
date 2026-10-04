/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 18:25:18 by pspuhler          #+#    #+#             */
/*   Updated: 2026/10/04 12:07:49 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{

	int	i;
	long value;

	// 1. S. 20 in PDF: If no argument is given, it stops and displays nothing.

	if (argc == 1)
	{
		return (0);
	}

	// 2. Check if int is valid

	i = 1;

	while (i < argc)
	{

		if (!(ft_syntax_check(argv)))
		{
			write(2, "Error\n", 6);
			return (1);
		}

		value = ft_atol(argv[i]);

		if (value > 2147483647 || value < -2147483648)
		{
			write(2, "Error\n", 6);
			return (1);
		}

		i++;
	}



	return (0);
}
