/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:09:13 by legrandc          #+#    #+#             */
/*   Updated: 2023/11/17 04:07:32 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				n;
	int				cost_r;
	int				cost_rr;
	int				ra_rb;
	int				rra_rrb;
	int				ra_rrb;
	int				rra_rb;
	int				total_cost;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rrr;
	int				rr;
	struct s_node	*target;
}					t_node;

typedef struct s_stack
{
	t_node			*first;
	t_node			*last;
	size_t			min_pos;
	size_t			len;
}					t_stack;

/* FUNCTIONS */
void				set_costs(t_stack *targets, t_stack *stack);
t_node				*get_min(t_stack *stack);
t_node				*create_node(int n);
void				sort_three(t_stack *stack);
void				push(t_stack *src, t_stack *dst, char *s);
void				swap(t_node *a, t_node *b);
void				rrotate(t_stack *stack, char *s);
void				rotate(t_stack *stack, char *s);
void				stack_pop(t_stack *stack);
void				add_begin(t_stack *stack, t_node *new_node);
void				add_end(t_stack *stack, t_node *new_node);

#endif
