/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:42:44 by legrandc          #+#    #+#             */
/*   Updated: 2023/11/17 04:07:25 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	aff_(t_stack *stack1)
// {
// 	size_t	i;
// 	t_node	*node;

// 	i = 0;
// 	node = stack1->first;
// 	while (i++ < stack1->len)
// 	{
// 		printf("%d\n", node->n);
// 		node = node->next;
// 	}
// }

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

int	is_sorted(t_stack *stack)
{
	size_t	i;
	t_node	*node;

	i = 0;
	node = stack->first;
	while (i + 1 < stack->len)
	{
		if (node->n > node->next->n)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	size_t			i;
	t_node			*node;
	t_node			*new_node;
	static t_stack	stack1;
	static t_stack	stack2;

	(void)ac;
	i = 1;
	while (av[i])
	{
		new_node = create_node(ft_atoi(av[i++]));
		if (!new_node)
			return (-1);
		add_end(&stack1, new_node);
		stack1.len++;
	}
	node = stack1.first;
	while (stack1.len > 3 && !is_sorted(&stack1))
		push(&stack1, &stack2, "pb\n");
	if (!is_sorted(&stack1))
		sort_three(&stack1);
	while (stack2.len > 0)
		push_back(&stack1, &stack2);
	get_min(&stack1);
	if (stack1.min_pos <= stack1.len / 2)
		while (stack1.min_pos--)
			rotate(&stack1, "ra\n");
	else
		while (stack1.min_pos++ != stack1.len)
			rrotate(&stack1, "rra\n");
	// aff_(&stack1);
	return (1);
}
