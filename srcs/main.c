/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:42:44 by legrandc          #+#    #+#             */
/*   Updated: 2023/11/24 12:46:11 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	static t_stack	stack1 = {0};
	static t_stack	stack2 = {0};

	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		++av;
	if (!av || !*av)
	{
		if (ac == 2)
			free(av);
		return (0);
	}
	parse_params(av, &stack1, ac);
	if (ac == 2)
		free_matrix(av);
	push_swap(&stack1, &stack2);
	free_stack(&stack1);
	return (0);
}
