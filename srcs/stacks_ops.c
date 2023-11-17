/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:06:40 by leo               #+#    #+#             */
/*   Updated: 2023/11/17 03:58:47 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_end(t_stack *stack, t_node *new_node)
{
	if (stack->last)
	{
		new_node->next = stack->first;
		new_node->prev = stack->last;
		stack->last->next = new_node;
		stack->first->prev = new_node;
	}
	else
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		stack->first = new_node;
	}
	stack->last = new_node;
}

void	add_begin(t_stack *stack, t_node *new_node)
{
	if (stack->first)
	{
		new_node->prev = stack->last;
		new_node->next = stack->first;
		stack->last->next = new_node;
		stack->first->prev = new_node;
	}
	else
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		stack->last = new_node;
	}
	stack->first = new_node;
}

void	stack_pop(t_stack *stack)
{
	if (stack->last == stack->first)
		ft_bzero(stack, sizeof(*stack));
	else
	{
		stack->first = stack->first->next;
		stack->first->prev = stack->last;
		stack->last->next = stack->first;
	}
}

t_node	*create_node(int n)
{
	t_node	*ret;

	ret = calloc(1, sizeof(*ret));
	if (!ret)
		return (NULL);
	ret->n = n;
	return (ret);
}

t_node	*get_min(t_stack *stack)
{
	long int	max;
	t_node		*node;
	t_node		*ret;
	size_t		i;

	i = 0;
	max = LONG_MAX;
	node = stack->first;
	while (i < stack->len)
	{
		if (node->n < max)
		{
			stack->min_pos = i;
			max = node->n;
			ret = node;
		}
		i++;
		node = node->next;
	}
	return (ret);
}
