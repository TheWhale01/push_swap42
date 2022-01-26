/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:39:26 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/26 16:51:20 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smart_rotate(t_pos pos, t_list **stack_a, t_list **stack_b)
{
	int	count;

	if (pos.stack_a * pos.stack_b < 0)
		return (0);
	count = ft_min(pos.stack_a, pos.stack_b);
	while (pos.stack_a > 0 && count)
	{
		rr(stack_a, stack_b);
		count--;
	}
	while (pos.stack_a < 0 && count)
	{
		rrr(stack_a, stack_b);
		count--;
	}
	return (1);
}

void	solve(t_pos pos, t_list **stack_a, t_list **stack_b)
{
	smart_rotate(pos, stack_a, stack_b);
}
