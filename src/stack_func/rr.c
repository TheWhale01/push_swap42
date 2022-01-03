/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:01:06 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/28 19:23:46 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, t_stack *none)
{
	int	i;
	int	tmp;

	i = -1;
	(void)none;
	tmp = a->stack[0];
	while (++i < a->len - 1)
		a->stack[i] = a->stack[i + 1];
	a->stack[i] = tmp;
}

void	rrb(t_stack *none, t_stack *b)
{
	int	i;
	int	tmp;

	i = -1;
	(void)none;
	tmp = b->stack[0];
	while (++i < b->len - 1)
		b->stack[i] = b->stack[i + 1];
	b->stack[i] = tmp;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, b);
	rrb(a, b);
}
