/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:52:01 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/30 15:25:08 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_list	*pre_sort(t_list *stack_a)
{
	t_list	*dup;
	t_list	*sorted;

	dup = ft_lstdup(stack_a, free);
	sorted = NULL;
	while (dup)
		ft_lstadd_back(&sorted, ft_lstpop(&dup, ft_lstmin(dup)));
	return (sorted);
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*med;
	t_list	*sorted;

	(void)stack_b;
	sorted = pre_sort(*stack_a);
	med = ft_lst_find_at_index(sorted, ft_lstsize(sorted) / 2);
	ft_lstclear(&sorted, free);
}
