/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:28:06 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/03 12:02:45 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	init_func(void (*ops[NB_OPS])(t_stack *, t_stack *))
{
	ops[0] = sa;
	ops[1] = sb;
	ops[2] = ss;
	ops[3] = pa;
	ops[4] = pb;
	ops[5] = ra;
	ops[6] = rb;
	ops[7] = rr;
	ops[8] = rra;
	ops[9] = rrb;
	ops[10] = rrr;
}

int	exec_comb(int n, int tab[NB_OPS],
			void (*ops[NB_OPS])(t_stack *, t_stack *), t_stack *a, t_stack *b)
{
	int	i;

	i = -1;
	while (++i < n)
		ops[tab[i]](a, b);
	if (check_sorted(a))
	{
		free_stack(b);
		return (1);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}

int	*sort(int n, void (*ops[NB_OPS])(t_stack *, t_stack *),
			t_stack *a, t_stack *b)
{
	int		i;
	int		*tab;
	t_stack	*a_cpy;
	t_stack	*b_cpy;

	i = -1;
	tab = malloc(sizeof(int) * NB_OPS);
	if (!tab)
		return (NULL);
	while (++i < n)
		tab[i] = 0;
	while (tab[0] <= NB_OPS - n)
	{
		a_cpy = stack_init(1, NULL);
		b_cpy = stack_init(1, NULL);
		if (!a_cpy || !b_cpy)
			return (NULL);
		a_cpy->stack = tabcpy(a->stack, a_cpy->stack, a->len);
		b_cpy->stack = tabcpy(b->stack, b_cpy->stack, b->len);
		tab[n - 1]++;
		i = 0;
		while (++i < n)
			if (tab[i] > (NB_OPS - n) + i)
				tab[i] = tab[i - 1]++ + 1;
		if (exec_comb(n, tab, ops, a, b))
			return (tab);
	}
	return (NULL);
}

int	solver(t_stack *a, t_stack *b)
{
	void	(*tab[NB_OPS])(t_stack *, t_stack *);

	init_func(tab);
	tab[7](a, b);
	tab[6](a, b);
	return (0);
}
