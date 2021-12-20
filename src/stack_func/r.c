/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:46:03 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/20 14:00:56 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_b(t_stack *stack)
{
	int	i;
	int	tmp;

	i = stack->len;
	tmp = stack->stack[i - 1];
	while (--i > 0)
		stack->stack[i] = stack->stack[i - 1];
	stack->stack[0] = tmp;
}

void	rr(t_stack *a, t_stack *b)
{
	ra_b(a);
	ra_b(b);
}
