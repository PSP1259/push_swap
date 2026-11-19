/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 17:00:00 by juan-jos          #+#    #+#             */
/*   Updated: 2026/11/19 13:13:00 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Returns 1 if 'arg' is exactly equal to the flag 'name', 0 otherwise.
 * Compares one character more than the length of 'name' so the end of
 * the string is included: "--simple123" does not match "--simple".
 */
static int	get_mode(const char *arg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (MODE_SIMPLE);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (MODE_MEDIUM);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (MODE_COMPLEX);
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (MODE_ADAPTIVE);
	return (MODE_NONE);
}

/*
 * Reads the leading "--" flags and sets the mode / bench options in data.
 * Returns the index of the first non-flag argument, or -1 on unknown flag.
 */
int	parse_flags(int argc, char **argv, t_data *data)
{
	int	i;
	int	m;

	if (!data)
		return (-1);
	i = 1;
	while (i < argc && ft_strncmp(argv[i], "--", 2) == 0)
	{
		m = get_mode(argv[i]);
		if (m != MODE_NONE && data->mode == MODE_NONE)
			data->mode = m;
		else if (ft_strncmp(argv[i], "--bench", 8) == 0 && !data->bench)
			data->bench = 1;
		else
			return (-1);
		i++;
	}
	if (data->mode == MODE_NONE)
		data->mode = MODE_ADAPTIVE;
	return (i);
}
