/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_top.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:35:20 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/20 10:35:52 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

t_list	*push_min_top(t_list **stack)
{
	int		len;
	int		index;
	t_list	*tmp;

	tmp = ft_lstdup(*stack, free);
	if (!tmp)
		return (free_lst(stack));
	len = ft_lstsize(tmp);
	index = get_min_index(tmp);
	if (index >= 0 && index <= len / 2)
		while (index--)
			ra_b(&tmp);
	else
		while (index++ < len)
			rra_b(&tmp);
	if (check_sorted(&tmp))
		return (free_lst(stack));
	return (tmp);
}
