/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:46:53 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/01 19:36:26 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b)
		return ;
	ft_lstadd_front(stack_a, pop_top(stack_b));
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a)
		return ;
	ft_lstadd_front(stack_b, pop_top(stack_a));
}
