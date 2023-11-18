/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:54:23 by legrandc          #+#    #+#             */
/*   Updated: 2023/11/18 23:42:31 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_cheapest(t_stack *stack)
{
	long	max;
	t_node	*node;
	size_t	i;
	t_node	*ret;

	max = LONG_MAX;
	node = stack->first;
	i = 0;
	while (i < stack->len)
	{
		if (node->total_cost < max)
		{
			max = node->total_cost;
			ret = node;
		}
		node = node->next;
		i++;
	}
	return (ret);
}

void	push_back(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;

	set_costs(stack_a, stack_b);
	cheapest = get_cheapest(stack_b);
	while (cheapest->ra--)
		rotate(stack_a, "ra\n");
	while (cheapest->rb--)
		rotate(stack_b, "rb\n");
	while (cheapest->rra--)
		rrotate(stack_a, "rra\n");
	while (cheapest->rrb--)
		rrotate(stack_b, "rrb\n");
	while (cheapest->rrr--)
	{
		rrotate(stack_a, "rrr\n");
		rrotate(stack_b, "");
	}
	while (cheapest->rr--)
	{
		rotate(stack_a, "rr\n");
		rotate(stack_b, "");
	}
	push(stack_b, stack_a, "pa\n");
}

void	push_swap(t_stack *stack1, t_stack *stack2)
{
	size_t	i;

	i = 0;
	while (i++ < stack1->len + stack2->len && stack1->len > 50
		&& stack1->len > stack2->len)
	{
		if (stack1->first->n <= stack1->average + 1)
			push(stack1, stack2, "pb\n");
		else
			rotate(stack1, "ra\n");
	}
	while (stack1->len > 3 && !is_sorted(stack1))
		push(stack1, stack2, "pb\n");
	sort_three(stack1);
	while (stack2->len > 0)
		push_back(stack1, stack2);
	get_min(stack1);
	if (stack1->min_pos <= stack1->len / 2)
		while (stack1->min_pos--)
			rotate(stack1, "ra\n");
	else
		while (stack1->min_pos++ != stack1->len)
			rrotate(stack1, "rra\n");
}
