/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:54:52 by leo               #+#    #+#             */
/*   Updated: 2023/11/17 04:00:34 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_different_costs(t_node *node)
{
	node->rra_rrb = ft_max(node->cost_rr, node->target->cost_rr);
	node->ra_rb = ft_max(node->cost_r, node->target->cost_r);
	node->rra_rb = node->cost_r + node->target->cost_rr;
	node->ra_rrb = node->cost_rr + node->target->cost_r;
	node->rrr = 0;
	node->rr = 0;
	node->rb = 0;
	node->rrb = 0;
	node->ra = 0;
	node->rra = 0;
}

int	calculate_cost(t_node *node)
{
	set_different_costs(node);
	if (node->rra_rrb < node->ra_rb && node->rra_rrb < node->rra_rb
		&& node->rra_rrb < node->ra_rrb)
	{
		node->rrr = ft_min(node->cost_rr, node->target->cost_rr);
		node->rrb = ft_max(0, node->cost_rr - node->target->cost_rr);
		node->rra = ft_max(0, node->target->cost_rr - node->cost_rr);
	}
	else if (node->ra_rb < node->ra_rrb && node->ra_rb < node->rra_rb)
	{
		node->rr = ft_min(node->cost_r, node->target->cost_r);
		node->rb = ft_max(0, node->cost_r - node->target->cost_r);
		node->ra = ft_max(0, node->target->cost_r - node->cost_r);
	}
	else if (node->rra_rb < node->ra_rrb)
	{
		node->rb = node->cost_r;
		node->rra = node->target->cost_rr;
	}
	else
	{
		node->rrb = node->cost_rr;
		node->ra = node->target->cost_r;
	}
	return (node->ra + node->rb + node->rra + node->rrb + node->rr + node->rrr);
}

void	assign_target(t_node *node, t_stack *targets)
{
	size_t		i;
	t_node		*target_node;
	long int	max;

	max = LONG_MAX;
	i = 0;
	target_node = targets->first;
	while (i < targets->len)
	{
		if (target_node->n > node->n && target_node->n < max)
		{
			node->target = target_node;
			max = target_node->n;
		}
		target_node = target_node->next;
		i++;
	}
	if (max == LONG_MAX)
		node->target = get_min(targets);
}

void	set_costs(t_stack *targets, t_stack *stack)
{
	size_t	i;
	t_node	*node;

	i = 0;
	node = stack->first;
	while (i < stack->len)
	{
		node->cost_r = i;
		node->cost_rr = (stack->len - i) % stack->len;
		if (targets)
		{
			set_costs(NULL, targets);
			assign_target(node, targets);
			node->total_cost = calculate_cost(node);
		}
		node = node->next;
		i++;
	}
}
