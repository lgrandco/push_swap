/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:42:44 by legrandc          #+#    #+#             */
/*   Updated: 2023/11/16 13:44:17 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aff_(t_stack *stack1)
{
	size_t	i;
	t_node	*node;

	i = 0;
	node = stack1->first;
	while (i++ < stack1->len)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

void	add_after(t_node *node, t_node *new)
{
	new->next = node->next;
	new->prev = node;
	node->next->prev = new;
	node->next = new;
}

void	add_end(t_stack *stack, t_node *new_node)
{
	if (stack->last)
		add_after(stack->last, new_node);
	else
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		stack->first = new_node;
	}
	stack->last = new_node;
}
void	add_before(t_node *node, t_node *new)
{
	new->prev = node->prev;
	new->next = node;
	node->prev->next = new;
	node->prev = new;
}
void	add_begin(t_stack *stack, t_node *new_node)
{
	if (stack->first)
		add_before(stack->first, new_node);
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
	{
		ft_bzero(stack, sizeof(*stack));
	}
	else
	{
		stack->first = stack->first->next;
		stack->first->prev = stack->last;
		stack->last->next = stack->first;
	}
}

void	push(t_stack *a, t_stack *b, char *s)
{
	t_node	*first;

	a->len--;
	b->len++;
	first = a->first;
	stack_pop(a);
	add_begin(b, first);
	ft_putstr_fd(s, 1);
}

void	rotate(t_stack *stack, char *s)
{
	stack->last = stack->first;
	stack->first = stack->first->next;
	ft_putstr_fd(s, 1);
}

void	rrotate(t_stack *stack, char *s)
{
	stack->first = stack->last;
	stack->last = stack->last->prev;
	ft_putstr_fd(s, 1);
}

void	rr_rotate(t_stack *stack1, t_stack *stack2)
{
	rotate(stack1, "rr\n");
	rotate(stack2, "");
}

void	rrr_rotate(t_stack *stack1, t_stack *stack2)
{
	rrotate(stack1, "rrr\n");
	rrotate(stack2, "");
}

void	swap(t_node *a, t_node *b)
{
	int	tmp;

	tmp = a->n;
	a->n = b->n;
	b->n = tmp;
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

t_node *new (int n)
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
void	get_target(t_node *node, t_stack *targets)
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

int	calculate_cost(t_node *node)
{
	int	total_rrr;
	int	total_rr;
	int	rb_rra;
	int	rrb_ra;

	total_rrr = ft_max(node->cost_rr, node->target->cost_rr);
	total_rr = ft_max(node->cost_r, node->target->cost_r);
	rb_rra = node->cost_r + node->target->cost_rr;
	rrb_ra = node->cost_rr + node->target->cost_r;
	node->rrr = 0;
	node->rr = 0;
	node->rb = 0;
	node->rrb = 0;
	node->ra = 0;
	node->rra = 0;
	if (total_rrr < total_rr && total_rrr < rb_rra && total_rrr < rrb_ra)
	{
		node->rrr = ft_min(node->cost_rr, node->target->cost_rr);
		node->rrb = ft_max(0, node->cost_rr - node->target->cost_rr);
		node->rra = ft_max(0, node->target->cost_rr - node->cost_rr);
	}
	else if (total_rr < rrb_ra && total_rr < rb_rra)
	{
		node->rr = ft_min(node->cost_r, node->target->cost_r);
		node->rb = ft_max(0, node->cost_r - node->target->cost_r);
		node->ra = ft_max(0, node->target->cost_r - node->cost_r);
	}
	else if (rb_rra < rrb_ra)
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

void	get_cost(t_stack *stack1, t_stack *stack2)
{
	size_t	i;
	t_node	*node;

	i = 0;
	node = stack2->first;
	while (i < stack2->len)
	{
		node->cost_r = i;
		node->cost_rr = (stack2->len - i) % stack2->len;
		if (stack1)
		{
			get_cost(NULL, stack1);
			get_target(node, stack1);
			node->total_cost = calculate_cost(node);
		}
		node = node->next;
		i++;
	}
}

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

void	push_back(t_stack *stack1, t_stack *stack2)
{
	t_node	*cheapest;

	get_cost(stack1, stack2);
	cheapest = get_cheapest(stack2);
	while (cheapest->ra--)
		rotate(stack1, "ra\n");
	while (cheapest->rb--)
		rotate(stack2, "rb\n");
	while (cheapest->rra--)
		rrotate(stack1, "rra\n");
	while (cheapest->rrb--)
		rrotate(stack2, "rrb\n");
	while (cheapest->rrr--)
		rrr_rotate(stack1, stack2);
	while (cheapest->rr--)
		rr_rotate(stack1, stack2);
	push(stack2, stack1, "pa\n");
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
		new_node = new (ft_atoi(av[i++]));
		if (!new_node)
			return (-1);
		add_end(&stack1, new_node);
		stack1.len++;
	}
	node = stack1.first;
	while (stack1.len > 3)
		push(&stack1, &stack2, "pb\n");
	sort_three(&stack1);
	// aff_(&stack2);
	while (stack2.len > 0)
		push_back(&stack1, &stack2);
	get_min(&stack1);
	// printf("pos:%zd\n", stack1.min_pos);
	if (stack1.min_pos <= stack1.len / 2)
		while (stack1.min_pos--)
			rotate(&stack1, "ra\n");
	else
		while (stack1.min_pos++ != stack1.len)
			rrotate(&stack1, "rra\n");
	// aff_(&stack1);
	return (1);
}
