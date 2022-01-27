/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:16:48 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/27 23:27:44 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack, t_list **none, char *str)
{
	t_list	*pop1;
	t_list	*pop2;

	(void)none;
	pop1 = pop_top(stack);
	pop2 = pop_top(stack);
	ft_lstadd_front(stack, pop1);
	ft_lstadd_front(stack, pop2);
	if (str)
		ft_putendl_fd(str, STDOUT);
}

void	sb(t_list **stack, t_list **none, char *str)
{
	t_list	*pop1;
	t_list	*pop2;

	(void)none;
	pop1 = pop_top(stack);
	pop2 = pop_top(stack);
	ft_lstadd_front(stack, pop1);
	ft_lstadd_front(stack, pop2);
	if (str)
		ft_putendl_fd(str, STDOUT);
}

void	ss(t_list **a, t_list **b, char *str)
{
	sa_b(a, NULL);
	sa_b(b, NULL);
	ft_putendl_fd("ss", STDOUT);
}
