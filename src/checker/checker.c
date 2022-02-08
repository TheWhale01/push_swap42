/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:32:42 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/01 20:26:49 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	do_op(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(line, "sa", 2))
		sa_b(stack_a, NULL);
	else if (!ft_strncmp(line, "sb", 2))
		sa_b(stack_b, NULL);
	else if (!ft_strncmp(line, "ss", 2))
		ss(stack_a, stack_b, NULL);
	else if (!ft_strncmp(line, "pa", 2))
		pa(stack_a, stack_b, NULL);
	else if (!ft_strncmp(line, "pb", 2))
		pb(stack_a, stack_b, NULL);
	else if (!ft_strncmp(line, "ra", 2))
		ra_b(stack_a, NULL);
	else if (!ft_strncmp(line, "rb", 2))
		ra_b(stack_b, NULL);
	else if (!ft_strncmp(line, "rr", 2))
		rr(stack_a, stack_b, NULL);
	else if (!ft_strncmp(line, "rra", 3))
		rra_b(stack_a, NULL);
	else if (!ft_strncmp(line, "rrb", 3))
		rra_b(stack_b, NULL);
	else if (!ft_strncmp(line, "rrr", 3))
		rrr(stack_a, stack_b, NULL);
	else
		return (0);
	return (1);
}

int	checker(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN);
		if (!line)
			break ;
		if (!do_op(line, stack_a, stack_b))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	if (!check_sorted(stack_a))
		return (0);
	return (1);
}
