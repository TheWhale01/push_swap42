/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:01:06 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/20 14:07:42 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_b(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->stack[0];
	while (++i < stack->len - 1)
		stack->stack[i] = stack->stack[i + 1];
	stack->stack[i] = tmp;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra_b(a);
	rra_b(b);
}
