/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:52:01 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/14 13:46:51 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	get_min_index(t_list *stack)
{
	int		min;
	int		index;
	t_list	*tmp;

	index = 0;
	tmp = stack;
	min = *(int *)tmp->content;
	while (tmp)
	{
		if (*(int *)tmp->content < min)
			min = *(int *)tmp->content;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp && *(int *)tmp->content != min)
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}

void	push_min_top(t_list **stack)
{
	int		len;
	int		index;

	len = ft_lstsize(*stack);
	index = get_min_index(*stack);
	if (index >= 0 && index <= len / 2)
		while (index--)
			ra_b(stack);
	else
		while (index++ < len)
			rra_b(stack);
	if (check_sorted(*stack))
		exit(0);
}

t_list	*lis(t_list	**stack)
{
	
}
