/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:21:25 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/21 15:36:20 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

void	exit_with_msg(char *str)
{
	ft_putstr_fd(str, STDERR);
	exit(0);
}

void	check_sorted(t_stack *stack)
{
	int	i;
	int	sorted;

	if (stack->len == 1)
	{
		free_stack(stack);
		exit(0);
	}
	i = -1;
	sorted = 1;
	while (++i < stack->len - 1)
		if (stack->stack[i] > stack->stack[i + 1])
			sorted = 0;
	if (sorted)
	{
		free_stack(stack);
		exit(0);
	}	
}

void	checker(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 1)
		exit(0);
	while (++i < ac)
	{
		j = 0;
		if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != '+')
			exit_with_msg("Error\n");
		else if (ft_strlen(av[i]) == 1 && (av[i][j] == '+' || av[i][j] == '-'))
			exit_with_msg("Error\n");
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				exit_with_msg("Error\n");
	}
}
