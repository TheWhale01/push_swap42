/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:54:26 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/01 19:36:40 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_list **stack_a, t_list **none)
{
	(void)none;
	ft_lstadd_front(stack_a, pop_bottom(stack_a));
}

void	rrb(t_list **none, t_list **stack_b)
{
	(void)none;
	ft_lstadd_front(stack_b, pop_bottom(stack_b));
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, stack_b);
	rrb(stack_b, stack_a);
}
