/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:06:40 by leo               #+#    #+#             */
/*   Updated: 2023/11/25 02:50:09 by leo              ###   ########.fr       */
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
	stack->len++;
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
	stack->len++;
	stack->first = new_node;
}

void	stack_pop(t_stack *stack)
{
	if (stack->last == stack->first)
	{
		stack->first = NULL;
		stack->last = NULL;
	}
	else
	{
		stack->first = stack->first->next;
		stack->first->prev = stack->last;
		stack->last->next = stack->first;
	}
	stack->len--;
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

void	aff_stacks(t_stack *stack1, t_stack *stack2)
{
	t_node	*node1;
	t_node	*node2;

	node1 = stack1->first;
	node2 = stack2->first;
	while (node1 || node2)
	{
		if (node1 && ft_printf(ANSI_COLOR_YELLOW "%-20d", node1->n))
			node1 = node1->next;
		else
			ft_printf(ANSI_COLOR_YELLOW "%-20s", "");
		if (node2 && ft_printf("%-20d", node2->n))
			node2 = node2->next;
		if (node1 == stack1->first)
			node1 = NULL;
		if (node2 == stack2->first)
			node2 = NULL;
		ft_printf("\n");
	}
	ft_printf("%-20c%c\n%-20c%-20c%s%u moves\n", '-', '-', 'a', 'b', ANSI_BOLD,
		stack1->moves);
	ft_printf(ANSI_COLOR_BLUE "%s\n%s", ft_memset((char [61]){0}, '-', 60),
		ANSI_COLOR_RESET);
}
