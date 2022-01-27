/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:28:07 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/25 15:51:57 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_b(t_list **stack, char *str)
{
	ft_lstadd_back(stack, pop_top(stack));
	if (str)
		ft_putendl_fd(str, STDOUT);
}

void	rr(t_list **a, t_list **b)
{
	ra_b(a, NULL);
	ra_b(b, NULL);
	ft_putendl_fd("rr", STDOUT);
}

void	rra_b(t_list **stack, char *str)
{
	ft_lstadd_front(stack, pop_bottom(stack));
	if (str)
		ft_putendl_fd(str, STDOUT);
}

void	rrr(t_list **a, t_list **b)
{
	rra_b(a, NULL);
	rra_b(b, NULL);
	ft_putendl_fd("rrr", STDOUT);
}
