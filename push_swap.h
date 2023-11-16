/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:09:13 by legrandc          #+#    #+#             */
/*   Updated: 2023/11/16 05:39:41 by leo              ###   ########.fr       */
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

#endif
