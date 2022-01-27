/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:22:33 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/27 23:24:50 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack, t_list **none, char *str)
{
	(void)none;
	ft_lstadd_front(stack, pop_bottom(stack));
	if (str)
		ft_putendl_fd(str, STDOUT);
}

void	rrb(t_list **stack, t_list **none, char *str)
{
	(void)none;
	ft_lstadd_front(stack, pop_bottom(stack));
	if (str)
		ft_putendl_fd(str, STDOUT);
}

void	rrr(t_list **a, t_list **b, char *str)
{
	rra(a, NULL, NULL);
	rrb(b, NULL, NULL);
	if (str)
		ft_putendl_fd(str, STDOUT);
}
