/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:46:03 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/22 10:49:07 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_b(t_stack *stack, t_stack *none)
{
	int	i;
	int	tmp;

	(void)none;
	i = stack->len;
	tmp = stack->stack[i - 1];
	while (--i > 0)
		stack->stack[i] = stack->stack[i - 1];
	stack->stack[0] = tmp;
}

void	rr(t_stack *a, t_stack *b)
{
	ra_b(a, b);
	ra_b(b, a);
}
