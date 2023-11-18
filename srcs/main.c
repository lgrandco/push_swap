/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:42:44 by legrandc          #+#    #+#             */
/*   Updated: 2023/11/18 02:52:23 by legrandc         ###   ########.fr       */
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

void	free_error(t_stack *stack)
{
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
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
			free_error(stack1);
		}
		add_end(stack1, new_node);
	}
}

int	main(int ac, char **av)
{
	static t_stack	stack1;
	static t_stack	stack2;

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
