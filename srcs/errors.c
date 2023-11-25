/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 01:29:47 by leo               #+#    #+#             */
/*   Updated: 2023/11/25 02:21:43 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_error(t_stack *stack1, t_stack *stack2, char *s)
{
	free_stack(stack1);
	free_stack(stack2);
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}

void	parse_params(char **av, t_stack *stack1, int ac)
{
	size_t	i;
	t_node	*new_node;

	i = 0;
	while (av[i])
	{
		new_node = create_node((av[i++]), stack1);
		if (!new_node)
		{
			if (ac == 2)
				free_matrix(av);
			free_error(stack1, NULL, "Error\n");
		}
		add_end(stack1, new_node);
	}
}
