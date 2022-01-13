/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:20:13 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/13 14:46:27 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

t_list	*stack_init(char **tab)
{
	int			i;
	t_list		*tmp;
	t_list		*stack;
	long long	nb;

	i = -1;
	stack = malloc(sizeof(t_list) * 1);
	if (!stack)
		return (NULL);
	stack->next = NULL;
	while (tab[++i])
	{
		nb = ft_atoll(tab[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (free_lst(&stack));
		tmp = ft_lstnew(&nb, sizeof(nb));
		if (!tmp)
			return (free_lst(&stack));
		ft_lstadd_front(&stack, tmp);
	}
	free_tab(tab);
	return (stack);
}
