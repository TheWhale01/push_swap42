/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:39:15 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/31 16:26:04 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	between(t_list *min, t_list *max, t_list *to_place, int rev)
{
	if (!rev && (*(int *)to_place->content > *(int *)min->content
			&& *(int *)to_place->content < *(int *)max->content))
		return (1);
	if (rev && (*(int *)to_place->content > *(int *)max->content
			&& *(int *)to_place->content < *(int *)min->content))
		return (1);
	return (0);
}

int	optimize(int index, int len)
{
	if (index > len / 2)
		return ((len - index) * -1);
	return (index);
}

t_pos	special(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int		len;
	t_pos	pos;

	len = ft_lstsize(stack_a);
	pos.stack_a = 0;
	if (len == 1)
	{
		if (*(int *)node->content > *(int *)stack_a->content)
			pos.stack_a = 1;
	}
	else if (*(int *)node->content > *(int *)ft_lstmax(stack_a)->content)
		pos.stack_a = optimize(ft_lstindex(ft_lstmax(stack_a),
					stack_a) + 1, len);
	else if (*(int *)node->content < *(int *)ft_lstmin(stack_a)->content)
		pos.stack_a = optimize(ft_lstindex(ft_lstmin(stack_a), stack_a), len);
	pos.stack_b = optimize(ft_lstindex(node, stack_b), ft_lstsize(stack_b));
	return (pos);
}

t_pos	get_pos(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int		rev;
	t_pos	pos;
	t_list	*tmp;

	rev = 0;
	pos.stack_a = 0;
	tmp = stack_a;
	while (tmp->next)
	{
		if (ft_lstindex(tmp, stack_a) > ft_lstsize(stack_a) / 2)
			rev = 1;
		if (between(tmp, tmp->next, node, rev))
		{
			pos.stack_a = optimize(ft_lstindex(tmp->next, stack_a),
					ft_lstsize(stack_a));
			if (rev)
				pos.stack_a -= 2;
			pos.stack_b = optimize(ft_lstindex(node, stack_b),
					ft_lstsize(stack_b));
			return (pos);
		}
		tmp = tmp->next;
	}
	return (special(node, stack_a, stack_b));
}

t_list	*cost(t_pos *pos, t_list *stack_a, t_list *stack_b)
{
	int		min_pos;
	t_pos	tmp_pos;
	t_list	*tmp;
	t_list	*min;

	min_pos = INT_MAX;
	tmp = stack_b;
	while (tmp)
	{
		tmp_pos = get_pos(tmp, stack_a, stack_b);
		if (abs(tmp_pos.stack_a) + abs(tmp_pos.stack_b) <= min_pos)
		{
			min_pos = abs(tmp_pos.stack_a) + abs(tmp_pos.stack_b);
			min = tmp;
			*pos = tmp_pos;
		}
		tmp = tmp->next;
	}
	return (min);
}
