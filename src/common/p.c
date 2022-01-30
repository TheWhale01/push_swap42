/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:23:33 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/30 15:11:30 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	if (!*b)
		return ;
	ft_lstadd_front(a, pop_top(b));
	ft_putendl_fd("pa", STDOUT);
}

void	pb(t_list **a, t_list **b)
{
	if (!*a)
		return ;
	ft_lstadd_front(b, pop_top(a));
	ft_putendl_fd("pb", STDOUT);
}
