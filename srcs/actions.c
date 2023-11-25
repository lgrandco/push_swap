/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:12:42 by leo               #+#    #+#             */
/*   Updated: 2023/11/25 02:11:23 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char *s)
{
	if (!stack->first)
		return ;
	stack->last = stack->first;
	stack->first = stack->first->next;
	ft_putstr_fd(s, 1);
}

void	rrotate(t_stack *stack, char *s)
{
	if (!stack->first)
		return ;
	stack->first = stack->last;
	stack->last = stack->last->prev;
	ft_putstr_fd(s, 1);
}

void	swap(t_node *a, t_node *b)
{
	int	tmp;

	tmp = a->n;
	a->n = b->n;
	b->n = tmp;
}

void	push(t_stack *src, t_stack *dst, char *s)
{
	t_node	*first;

	if (src->first == NULL)
		return ;
	first = src->first;
	stack_pop(src);
	add_begin(dst, first);
	ft_putstr_fd(s, 1);
}

void	sort_three(t_stack *stack)
{
	if (stack->first->n > stack->first->next->n
		&& stack->first->n > stack->last->n)
		rotate(stack, "ra\n");
	else if (stack->first->next->n > stack->first->n
		&& stack->first->next->n > stack->last->n)
		rrotate(stack, "rra\n");
	if (stack->first->n > stack->first->next->n)
	{
		swap(stack->first, stack->first->next);
		ft_putstr_fd("sa\n", 1);
	}
}
