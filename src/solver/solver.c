/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:39:26 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/26 17:54:33 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_rotate(t_pos *pos, t_list **stack_a, t_list **stack_b)
{
	if (pos->stack_a * pos->stack_b < 0)
		return ;
	while (pos->stack_a > 0 && pos->stack_b > 0)
	{
		rr(stack_a, stack_b);
		pos->stack_a--;
		pos->stack_b--;
	}
	while (pos->stack_a < 0 && pos->stack_b < 0)
	{
		rrr(stack_a, stack_b);
		pos->stack_a++;
		pos->stack_b++;
	}
}

void	place_in_stack(t_pos *pos, t_list **stack_a, t_list **stack_b)
{
	smart_rotate(pos, stack_a, stack_b);
	while (pos->stack_a-- > 0)
		ra_b(stack_a, "ra");
	while (++pos->stack_a < 0)
		rra_b(stack_a, "rra");
	while (--pos->stack_b > 0)
		ra_b(stack_b, "rb");
	while (++pos->stack_b < 0)
		rra_b(stack_b, "rrb");
	pa(stack_a, stack_b, "pa");
}

//	Problem in cost()
void	solve(t_list **stack_a, t_list **stack_b)
{
	t_pos	pos;

	non_lis_to_b(stack_a, stack_b);
	ft_printf("---------------\n");
	while (*stack_b)
	{
		cost(&pos, *stack_a, *stack_b);
		place_in_stack(&pos, stack_a, stack_b);
		ft_printf("stack : ");
		display_lst(*stack_a);
		ft_printf("stack_b : ");
		display_lst(*stack_b);
	}
}
