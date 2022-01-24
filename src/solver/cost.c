/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:39:15 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/24 14:50:07 by hubretec         ###   ########.fr       */
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

int	between(t_list *min, t_list *max, t_list *to_place, int rev)
{
	if (!rev && (*(int *)to_place->content > *(int *)min->content
			&& *(int *)to_place->content < *(int *)max->content))
		return (1);
	else if (rev && (*(int *)to_place->content > *(int *)min->content
			&& *(int *)to_place->content < *(int *)max->content))
		return (1);
	return (0);
}

int	nb_moves(t_list	*node, t_list *stack_a, t_list *stack_b)
{
	int		rev;
	int		tmp_index;
	int		moves;
	t_list	*tmp;

	rev = 0;
	tmp = stack_a;
	tmp_index = find_index(node, stack_b);
	moves = tmp_index + 1;
	if (between(stack_a, ft_lstlast(stack_a), node, 0))
		return (moves + 1);
	while (tmp->next)
	{
		if (moves - tmp_index > ft_lstsize(stack_a) / 2)
			rev = 1;
		if (between(tmp, tmp->next, node, rev))
		{
			if (rev)
				return (moves);
			return (ft_lstsize(stack_a) - tmp_index);
		}
		moves++;
		tmp = tmp->next;
	}
	return (find_index(ft_lstmax(stack_a), stack_a));
}
