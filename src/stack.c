/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:20:13 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/13 15:30:39 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	check_sorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (*(int *)tmp->content < *(int *)tmp->next->content)
		{
			ft_lstclear(&lst, free);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_list	*stack_init(char **tab)
{
	int			i;
	t_list		*tmp;
	t_list		*stack;
	long long	nb;

	i = -1;
	stack = NULL;
	while (tab[++i])
	{
		nb = ft_atoll(tab[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (free_lst(&stack));
		tmp = ft_lstnew(&nb, sizeof(int));
		if (!tmp)
			return (free_lst(&stack));
		ft_lstadd_back(&stack, tmp);
	}
	free_tab(tab);
	//if (check_sorted(stack))
	//	return (free_lst(&stack));
	return (stack);
}
