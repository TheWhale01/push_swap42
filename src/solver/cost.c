/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:39:15 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/21 15:15:12 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_list	*ft_lstmax(t_list *stack)
{
	t_list	*max;
	t_list	*tmp;

	max = NULL;
	tmp = stack;
	while (tmp)
	{
		if (!max || (*(int *)max->content < *(int *)tmp->content))
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	between(int min, int max, int to_place, int rev)
{
	if (!rev && (to_place >= min && to_place <= max))
		return (1);
	else if (rev && (to_place >= max && to_place <= min))
		return (1);
	return (0);
}

int	nb_moves_in_stack(t_list *node, t_list *stack)
{
	int		len;
	int		moves;
	t_list	*tmp;

	len = ft_lstsize(stack);
	moves = 0;
	tmp = stack;
	while (tmp
		&& *(int *)node->content != *(int *)tmp->content)
	{
		moves++;
		tmp = tmp->next;
	}
	if (moves <= len / 2)
		return (moves);
	else
		return (len - moves);
}

int	nb_moves_out_stack(t_list *node, t_list *stack)
{
	int		rev;
	int		len;
	int		index;
	t_list	*tmp;

	rev = 0;
	len = ft_lstsize(stack);
	index = 0;
	tmp = stack;
	while (tmp->next)
	{
		if (index > len / 2)
			rev = 1;
		if (between(*(int *)tmp->content, *(int *)tmp->next->content,
				*(int *)node->content, rev))
		{
			if (rev)
				return (len - index);
			return (index);
		}
		index++;
		tmp = tmp->next;
	}
	return (find_index(ft_lstmax(stack), stack));
}
