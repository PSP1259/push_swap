/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:32:42 by pspuhler          #+#    #+#             */
/*   Updated: 2026/11/16 15:32:46 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
** Matches rotation instructions (ra, rb, rr, rra, rrb, rrr) and sets *op.
** Returns 1 if valid, or 0 if the instruction is unknown.
*/
static int	parse_rotates(char *line, t_op *op)
{
	if (ft_strncmp(line, "ra\n", 4) == 0)
		*op = OP_RA;
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		*op = OP_RB;
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		*op = OP_RR;
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		*op = OP_RRA;
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		*op = OP_RRB;
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		*op = OP_RRR;
	else
		return (0);
	return (1);
}

/*
** Matches swap and push instructions (sa, sb, ss, pa, pb) and sets *op,
** or delegates to parse_rotates. Returns 1 if valid, 0 if invalid.
*/
static int	parse_line(char *line, t_op *op)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		*op = OP_SA;
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		*op = OP_SB;
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		*op = OP_SS;
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		*op = OP_PA;
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		*op = OP_PB;
	else
		return (parse_rotates(line, op));
	return (1);
}

/*
** Reads a single line from standard input (fd 0) into a fixed buffer.
** Returns 1 if a line was read, 0 on EOF, or -1 on read error.
*/
static int	read_single_line(char *buf)
{
	int		i;
	int		ret;
	char	c;

	i = 0;
	ret = read(0, &c, 1);
	while (ret > 0)
	{
		if (i < 5)
			buf[i++] = c;
		if (c == '\n')
			break ;
		ret = read(0, &c, 1);
	}
	buf[i] = '\0';
	if (ret < 0)
		return (-1);
	return (i > 0);
}

/*
** Reads all instructions from stdin until EOF, validates each line,
** and appends the corresponding t_op to data->ops using record().
*/
int	read_instructions(t_data *data)
{
	char	line[6];
	t_op	op;
	int		status;

	status = read_single_line(line);
	while (status > 0)
	{
		if (!parse_line(line, &op) || !record(data, op))
			return (0);
		status = read_single_line(line);
	}
	if (status < 0)
		return (0);
	return (1);
}
