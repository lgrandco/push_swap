/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:09:13 by legrandc          #+#    #+#             */
/*   Updated: 2023/12/12 15:47:36 by legrandc         ###   ########.fr       */
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
	int				average;
	size_t			moves;
}					t_stack;

/* FUNCTIONS */
void				aff_stacks(t_stack *stack1, t_stack *stack2);
void				free_error(t_stack *stack1, t_stack *stack2, char *s);
void				parse_params(char **av, t_stack *stack1, int ac);
void				push_swap(t_stack *stack1, t_stack *stack2);
int					is_sorted(t_stack *stack);
void				free_stack(t_stack *stack);
t_node				*create_node(char *s, t_stack *stack);
void				set_costs(t_stack *targets, t_stack *stack);
t_node				*get_min(t_stack *stack);
void				sort_three(t_stack *stack);
void				push(t_stack *src, t_stack *dst, char *s);
void				swap(t_stack *stack);
void				rrotate(t_stack *stack, char *s);
void				rotate(t_stack *stack, char *s);
void				stack_pop(t_stack *stack);
void				add_begin(t_stack *stack, t_node *new_node);
void				add_end(t_stack *stack, t_node *new_node);

#endif
