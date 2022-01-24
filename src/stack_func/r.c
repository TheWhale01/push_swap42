/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:28:07 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/24 15:27:29 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_b(t_list **stack)
{
	ft_lstadd_front(stack, pop_top(stack));
	ft_putstr("ra\n");
}

void	rr(t_list **a, t_list **b)
{
	ra_b(a);
	ra_b(b);
	ft_putstr("rr\n");
}

void	rra_b(t_list **stack)
{
	ft_lstadd_back(stack, pop_bottom(stack));
	ft_putstr("rra\n");
}

void	rrr(t_list **a, t_list **b)
{
	rra_b(a);
	rra_b(b);
	ft_putstr("rrr\n");
}
