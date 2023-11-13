/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:42:44 by legrandc          #+#    #+#             */
/*   Updated: 2023/11/13 09:08:37 by legrandc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_after(t_node *node, t_node *new)
{
	new->next = node->next;
	new->prev = node;
	node->next->prev = new;
	node->next = new;
}

void	add_end(t_stack *stack, t_node *new_node)
{
	if ((*stack).last)
		add_after((*stack).last, new_node);
	else
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		(*stack).first = new_node;
	}
	(*stack).last = new_node;
}
void	add_before(t_node *node, t_node *new)
{
	new->next = node;
	node->prev->next = new;
}
void	add_begin(t_stack *stack, t_node *new_node)
{
	if ((*stack).first)
		add_before((*stack).first, new_node);
	else
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		(*stack).last = new_node;
	}
	(*stack).first = new_node;
}

void	stack_pop(t_stack *stack)
{
	stack->first = stack->first->next;
	stack->last->next = stack->first;
}

void	push(t_stack *a, t_stack *b)
{
	t_node	*first;

	first = a->first;
	stack_pop(a);
	add_begin(b, first);
}

t_node *new (int n)
{
	t_node	*ret;

	ret = malloc(sizeof(*ret));
	if (!ret)
		return (NULL);
	ret->n = n;
	return (ret);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	stack;
	t_stack	stack2;
	int		l1;
	int		l2;
	t_node	*node;
	t_node	*new_node;

	l2 = 4;
	(void)ac;
	l1 = 0;
	i = 1;
	stack.last = NULL;
	stack2.last = NULL;
	stack2.first = NULL;
	while (av[i])
	{
		new_node = new (ft_atoi(av[i++]));
		if (!new_node)
			return (-1);
		add_end(&stack, new_node);
		l1++;
	}
	node = stack.first;
	while (l1--)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
	push(&stack, &stack2);
	push(&stack, &stack2);
	push(&stack2, &stack);
	push(&stack2, &stack);
	node = stack2.first;
	while (l2--)
	{
		printf("2:%d\n", node->n);
		node = node->next;
	}
	l1 = 1;
	node = stack.first;
	while (l1--)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
