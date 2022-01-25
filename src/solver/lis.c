/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:52:01 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/25 11:43:43 by hubretec         ###   ########.fr       */
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
	ft_lstclear(&stack, free);
}

void	non_lis_to_b(t_list **a, t_list *tmp, t_list **b)
{
	int		len;
	int		*lis;

	len = 0;
	lis = ft_calloc(ft_lstsize(*a), sizeof(int));
	if (!lis)
		return ;
	get_lis(tmp, lis, &len);
	while (ft_lstsize(*a) != len)
	{
		if (!is_in(*(int *)(*a)->content, lis, len))
			pb(a, b);
		else
			ra_b(a);
	}
	free(lis);
}
