/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:23:33 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/18 16:54:37 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	if (!*b)
		return ;
	ft_lstadd_back(a, pop_top(b));
	ft_putstr("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*popped;

	if (!*a)
		return ;
	popped = pop_top(a);
	popped->prev = NULL;
	ft_lstadd_back(b, popped);
	ft_putstr("pb\n");
}
