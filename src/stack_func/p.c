/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:23:33 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/13 16:57:04 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	if (!*b)
		return ;
	ft_lstadd_back(a, pop_top(b));
}

void	pb(t_list **a, t_list **b)
{
	if (!*a)
		return ;
	ft_lstadd_back(b, pop_top(a));
}
