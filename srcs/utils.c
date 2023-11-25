/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:58:30 by legrandc          #+#    #+#             */
/*   Updated: 2023/11/25 02:54:31 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_bool(const char *nptr, int *ptr)
{
	long int	ret;
	int			sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-' && ++nptr)
		sign = -1;
	if (!ft_isdigit(*nptr))
		return (0);
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			return (0);
		ret = ret * 10 + *nptr - '0';
		nptr++;
	}
	ret *= sign;
	*ptr = ret;
	return (ret <= INT_MAX && ret >= INT_MIN);
}

int	is_present(t_stack *stack, int n)
{
	t_node	*node;
	size_t	i;

	node = stack->first;
	i = 0;
	while (i++ < stack->len)
	{
		if (node->n == n)
			return (1);
		node = node->next;
	}
	return (0);
}

t_node	*create_node(char *s, t_stack *stack)
{
	t_node	*ret;
	int		n;

	if (!s || !ft_atoi_bool(s, &n) || is_present(stack, n))
		return (NULL);
	ret = calloc(1, sizeof(*ret));
	if (!ret)
		return (NULL);
	ret->n = n;
	stack->average += ((n - stack->average) / (int)(stack->len + 1));
	return (ret);
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

void	free_stack(t_stack *stack)
{
	size_t	i;
	t_node	*node;
	t_node	*next;

	i = 0;
	if (!stack)
		return ;
	node = stack->first;
	while (i++ < stack->len)
	{
		next = node->next;
		free(node);
		node = next;
	}
}
