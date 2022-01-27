/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:28:07 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/27 23:25:33 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack, t_list **none, char *str)
{
	(void)none;
	ft_lstadd_back(stack, pop_top(stack));
	if (str)
		ft_putendl_fd(str, STDOUT);
}

void	rb(t_list **stack, t_list **none, char *str)
{
	(void)none;
	ft_lstadd_back(stack, pop_top(stack));
	if (str)
		ft_putendl_fd(str, STDOUT);
}

void	rr(t_list **a, t_list **b, char *str)
{
	ra_b(a, NULL, NULL);
	ra_b(b, NULL, NULL);
	ft_putendl_fd("rr", STDOUT);
}
