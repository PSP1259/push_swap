/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:23:54 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/26 17:55:04 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

typedef struct s_data
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_op	*ops;
	int		n_ops;
	int		capacity;
}	t_data;

/*Function Prototypes*/
t_node	*ft_create_node(int value);
void	ft_add_node_back(t_node **lst, t_node *new);
void	print_list(t_node *head);
void	free_list(t_node **head);
int		rotate(t_node **stack);
int		rev_rotate(t_node **stack);
int		swap(t_node **stack);
int		push(t_node **src_stack, t_node **dest_stack);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
int		init_data(t_data *data);
int		record(t_data *data, t_op op);
void	print_ops(t_data *data);
void	free_all(t_data *data);
int		parse_args(int argc, char **argv, t_data *data);
#endif
