/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 01:25:02 by leo               #+#    #+#             */
/*   Updated: 2023/11/19 06:12:20 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid(char *s)
{
	return (!ft_strncmp(s, "ra\n", 4) || !ft_strncmp(s, "rb\n", 4)
		|| !ft_strncmp(s, "rra\n", 4) || !ft_strncmp(s, "rrb\n", 4)
		|| !ft_strncmp(s, "rr\n", 4) || !ft_strncmp(s, "rrr\n", 4)
		|| !ft_strncmp(s, "sa\n", 4) || !ft_strncmp(s, "sb\n", 4)
		|| !ft_strncmp(s, "ss\n", 4) || !ft_strncmp(s, "pa\n", 4)
		|| !ft_strncmp(s, "pb\n", 4));
}

static void	exec_command(t_stack *stack1, t_stack *stack2, char *command)
{
	if (!is_valid(command))
		free_error(stack1);
	if (!ft_strncmp(command, "ra\n", 4) || !ft_strncmp(command, "rr\n", 4))
		rotate(stack1, "");
	if (!ft_strncmp(command, "rb\n", 4) || !ft_strncmp(command, "rr\n", 4))
		rotate(stack2, "");
	if (!ft_strncmp(command, "rra\n", 4) || !ft_strncmp(command, "rrr\n", 4))
		rrotate(stack1, "");
	if (!ft_strncmp(command, "rrb\n", 4) || !ft_strncmp(command, "rrr\n", 4))
		rrotate(stack2, "");
	if (!ft_strncmp(command, "sa\n", 4) || !ft_strncmp(command, "ss\n", 4))
		swap(stack1->first, stack1->first->next);
	if (!ft_strncmp(command, "sb\n", 4) || !ft_strncmp(command, "ss\n", 4))
		swap(stack1->first, stack1->first->next);
	if (!ft_strncmp(command, "pa\n", 4))
		push(stack2, stack1, "");
	if (!ft_strncmp(command, "pb\n", 4))
		push(stack1, stack2, "");
	free(command);
	stack1->moves++;
}

#include <fcntl.h>

static void	exec_commands(t_stack *stack1, t_stack *stack2)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		exec_command(stack1, stack2, command);
		aff_stacks(stack1, stack2);
		command = get_next_line(0);
	}
}

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
	aff_stacks(&stack1, &stack2);
	exec_commands(&stack1, &stack2);
	if (!is_sorted(&stack1) || stack2.len)
		free_error(&stack1);
	free_stack(&stack1);
	ft_printf(ANSI_COLOR_GREEN "OK\n`9");
	return (0);
}
