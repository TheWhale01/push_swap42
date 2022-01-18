/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:20:13 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/18 14:23:52 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	check_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	ft_lstclear(stack, free);
	return (1);
}

t_list	*stack_init(char **tab)
{
	int			i;
	t_list		*tmp;
	t_list		*stack;
	long long	nb;

	i = -1;
	stack = NULL;
	while (tab && tab[++i])
	{
		nb = ft_atoll(tab[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (free_lst(&stack));
		tmp = ft_lstnew(&nb, sizeof(tmp->content));
		if (!tmp)
			return (free_lst(&stack));
		ft_lstadd_back(&stack, tmp);
	}
	free_tab(tab);
	if (check_sorted(&stack))
		return (free_lst(&stack));
	return (stack);
}
