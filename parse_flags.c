/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 17:00:00 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/18 17:00:00 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Returns 1 if 'arg' is exactly equal to the flag 'name', 0 otherwise.
 * Compares one character more than the length of 'name' so the end of
 * the string is included: "--simple123" does not match "--simple".
 */
static int	is_flag(const char *arg, const char *name)
{
	return (ft_strncmp(arg, name, ft_strlen(name) + 1) == 0);
}

/*
 * Reads the leading "--" flags and sets the mode / bench options in data.
 * Returns the index of the first non-flag argument, or -1 on unknown flag.
 */
int	parse_flags(int argc, char **argv, t_data *data)
{
	int	i;

	if (!data)
		return (-1);
	i = 1;
	while (i < argc && ft_strncmp(argv[i], "--", 2) == 0)
	{
		if (is_flag(argv[i], "--simple"))
			data->mode = MODE_SIMPLE;
		else if (is_flag(argv[i], "--medium"))
			data->mode = MODE_MEDIUM;
		else if (is_flag(argv[i], "--complex"))
			data->mode = MODE_COMPLEX;
		else if (is_flag(argv[i], "--adaptive"))
			data->mode = MODE_ADAPTIVE;
		else if (is_flag(argv[i], "--bench"))
			data->bench = 1;
		else
			return (-1);
		i++;
	}
	return (i);
}
