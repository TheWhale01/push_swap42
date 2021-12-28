/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:28:06 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/28 18:51:37 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	init_func(void (*tab[NB_OPS])(t_stack *, t_stack *))
{
	tab[0] = sa_b;
	tab[1] = ss;
	tab[2] = ra_b;
	tab[3] = rr;
	tab[4] = rra_b;
	tab[5] = rrr;
	tab[6] = pa;
	tab[7] = pb;
}

int	sort(int stop, t_stack *a, t_stack *b)
{
	(void)stop;
	(void)a;
	(void)b;
	return (0);
}

int	solver(t_stack *a, t_stack *b)
{
	void	(*tab[NB_OPS])(t_stack *, t_stack *);

	init_func(tab);
	tab[7](a, b);
	tab[6](a, b);
	return (0);
}
