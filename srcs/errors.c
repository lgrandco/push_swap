/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 01:29:47 by leo               #+#    #+#             */
/*   Updated: 2023/11/19 01:30:04 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_error(t_stack *stack)
{
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	parse_params(char **av, t_stack *stack1, int ac)
{
	size_t i;
	t_node *new_node;

	i = 0;
	while (av[i])
	{
		new_node = create_node((av[i++]), stack1);
		if (!new_node)
		{
			if (ac == 2)
				free_matrix(av);
			free_error(stack1);
		}
		add_end(stack1, new_node);
	}
}
