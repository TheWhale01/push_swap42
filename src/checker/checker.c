/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:32:42 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/01 19:43:04 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"

void	init_tab(void (*tab[11])(t_list **, t_list **))
{
	tab[0] = sa;
	tab[1] = sb;
	tab[2] = ss;
	tab[3] = pa;
	tab[4] = pb;
	tab[5] = ra;
	tab[6] = rb;
	tab[7] = rr;
	tab[8] = rra;
	tab[9] = rrb;
	tab[10] = rrr;
}

void	init_ops(char *ops[11])
{
	ops[0] = "sa\n";
	ops[1] = "sb\n";
	ops[2] = "ss\n";
	ops[3] = "pa\n";
	ops[4] = "pb\n";
	ops[5] = "ra\n";
	ops[6] = "rb\n";
	ops[7] = "rr\n";
	ops[8] = "rra\n";
	ops[9] = "rrb\n";
	ops[10] = "rrr\n";
}

int	do_op(void (*tab[11])(t_list **, t_list **),
	char *ops[11], char *line, t_list **stack_a, t_list **stack_b)
{
	int		i;

	i = -1;
	while (++i < 11)
	{
		if (!ft_strcmp(ops[i], line))
		{
			(*tab[i])(stack_a, stack_b);
			return (1);
		}
	}
	return (0);
}

int	checker(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	char	*ops[11];
	void	(*tab[11])(t_list **, t_list **);

	init_ops(ops);
	init_tab(tab);
	while (1)
	{
		line = get_next_line(STDIN);
		if (!line)
			break ;
		if (!do_op(tab, ops, line, stack_a, stack_b))
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
