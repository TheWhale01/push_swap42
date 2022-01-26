/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:39:15 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/26 14:18:02 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

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

int	optimize(int index, int len)
{
	if (index > len / 2)
		return ((len - index) * -1);
	return (index);
}

t_pos	special(t_list *stack_a, t_list *stack_b, t_list *node)
{
	t_pos	pos;

	if (between(stack_a, ft_lstlast(stack_a), node, 0))
	{
		pos.stack_a = 1;
		pos.stack_b = optimize(ft_lstindex(node, stack_b), ft_lstsize(stack_b));
	}
	else
	{
		pos.stack_a = optimize(ft_lstindex(ft_lstmax(stack_a), stack_a) + 1,
				ft_lstsize(stack_a));
		pos.stack_b = optimize(ft_lstindex(node, stack_b), ft_lstsize(stack_b));
	}
	return (pos);
}

t_pos	get_pos(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int		rev;
	t_pos	pos;
	t_list	*tmp;

	rev = 0;
	pos.stack_a = 0;
	pos.stack_b = 0;
	tmp = stack_a;
	while (tmp->next)
	{
		if (!rev && ft_lstindex(tmp, stack_a) > ft_lstsize(stack_a) / 2)
			rev = 1;
		if (between(tmp, tmp->next, node, rev))
		{
			pos.stack_a = optimize(ft_lstindex(tmp, stack_a) + 1,
					ft_lstsize(stack_a));
			pos.stack_b = optimize(ft_lstindex(node, stack_b),
					ft_lstsize(stack_b));
			return (pos);
		}
		tmp = tmp->next;
	}
	return (special(stack_a, stack_b, node));
}

t_list	*cost(t_list *stack_a, t_list *stack_b)
{
	int		min_pos;
	t_pos	pos;
	t_list	*tmp;
	t_list	*min;

	min = NULL;
	tmp = stack_b;
	while (tmp)
	{
		pos = get_pos(tmp, stack_a, stack_b);
		if (!min || abs(pos.stack_a) + abs(pos.stack_b) <= min_pos)
		{
			min_pos = abs(pos.stack_a) + abs(pos.stack_b);
			min = tmp;
		}
		tmp = tmp->next;
	}
	return (min);
}
