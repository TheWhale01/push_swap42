/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:46:03 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/28 19:35:38 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, t_stack *none)
{
	int	i;
	int	tmp;

	if (!a->len)
		return ;
	(void)none;
	i = a->len;
	tmp = a->stack[i - 1];
	while (--i > 0)
		a->stack[i] = a->stack[i - 1];
	a->stack[0] = tmp;
}

void	rb(t_stack *none, t_stack *b)
{
	int	i;
	int	tmp;

	if (!b->len)
		return ;
	(void)none;
	i = b->len;
	tmp = b->stack[i - 1];
	while (--i > 0)
		b->stack[i] = b->stack[i - 1];
	b->stack[0] = tmp;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, b);
	rb(a, b);
}
