/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:52:01 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/17 15:47:18 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	ft_lstindex(t_list *stack, t_list *node)
{
	int		index;
	t_list	*tmp;

	tmp = stack;
	index = 0;
	while (tmp && *(int *)tmp->content != *(int *)node->content)
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}

t_list	*find_next(t_list *stack, void *content)
{
	int		min;
	t_list	*tmp;
	t_list	*next;

	tmp = stack;
	min = INT_MAX;
	while (tmp)
	{
		if (*(int *)tmp->content > *(int *)content
			&& *(int *)tmp->content - *(int *)content < min)
		{
			min = *(int *)tmp->content - *(int *)content;
			next = tmp;
		}
		tmp = tmp->next;
	}
	return (next);
}

t_list	*get_lis(t_list *stack)
{
	t_list	*tmp;
	t_list	*lis;
	t_list	*next;

	lis = NULL;
	tmp = stack->next;
	ft_lstadd_back(&lis, ft_lstnew(stack->content, sizeof(stack->content)));
	while (tmp)
	{
		if (*(int *)ft_lstlast(lis)->content < *(int *)tmp->content)
			ft_lstadd_back(&lis, ft_lstnew(tmp->content, sizeof(tmp->content)));
		else
		{
			next = find_next(stack, tmp->content);
			ft_lstreplace_index(lis, next,
				ft_lstindex(lis, next) - *(int *)lis->content);
		}
		tmp = tmp->next;
	}
	return (lis);
}
