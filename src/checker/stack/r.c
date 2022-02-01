/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:50:18 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/01 19:36:31 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_list **stack_a, t_list **none)
{
	(void)none;
	ft_lstadd_back(stack_a, pop_top(stack_a));
}

void	rb(t_list **none, t_list **stack_b)
{
	(void)none;
	ft_lstadd_back(stack_b, pop_top(stack_b));
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, stack_b);
	rb(stack_b, stack_a);
}
