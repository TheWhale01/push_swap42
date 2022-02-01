/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:37:52 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/01 19:36:45 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list **stack_a, t_list **none)
{
	t_list	*pop1;
	t_list	*pop2;

	(void)none;
	pop1 = pop_top(stack_a);
	pop2 = pop_top(stack_a);
	ft_lstadd_front(stack_a, pop1);
	ft_lstadd_front(stack_a, pop2);
}

void	sb(t_list **none, t_list **stack_b)
{
	t_list	*pop1;
	t_list	*pop2;

	(void)none;
	pop1 = pop_top(stack_b);
	pop2 = pop_top(stack_b);
	ft_lstadd_front(stack_b, pop1);
	ft_lstadd_front(stack_b, pop2);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, stack_b);
	sb(stack_b, stack_a);
}
