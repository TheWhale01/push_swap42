/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:52:01 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/25 16:18:07 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	max(int n, int m)
{
	if (n > m)
		return (n);
	return (m);
}

int	is_in(int n, int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
		if (tab[i++] == n)
			return (1);
	return (0);
}

void	get_lis(t_list *stack, int	*lis, int *len)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	j = -1;
	tmp = stack;
	while (tmp && ++j != -1)
	{
		i = 0;
		while (i != j)
		{
			k = (i + j) / 2;
			if (lis[k] < *(int *)tmp->content)
				i = k + 1;
			else
				j = k;
		}
		lis[i] = *(int *)tmp->content;
		*len = max(i + 1, *len);
		tmp = tmp->next;
	}
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
	index = ft_lstindex(ft_lstmin(*stack), *stack);
	if (index >= 0 && index <= len / 2)
		while (index--)
			ra_b(&tmp, NULL);
	else
		while (index++ < len)
			rra_b(&tmp, NULL);
	if (check_sorted(&tmp))
		return (free_lst(stack));
	return (tmp);
}

void	non_lis_to_b(t_list **a, t_list **b)
{
	int		len;
	int		*lis;
	t_list	*tmp;

	len = 0;
	lis = ft_calloc(ft_lstsize(*a), sizeof(int));
	if (!lis)
		return ;
	tmp = push_min_top(a);
	get_lis(tmp, lis, &len);
	ft_lstclear(&tmp, free);
	while (ft_lstsize(*a) != len)
	{
		if (!is_in(*(int *)(*a)->content, lis, len))
			pb(a, b, "pb");
		else
			ra_b(a, "ra");
	}
	free(lis);
}
