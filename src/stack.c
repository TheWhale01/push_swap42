/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:20:13 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/12 16:16:06 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

t_list	*stack_init(char **tab)
{
	int		i;
	t_list	*tmp;
	t_list	*stack;

	i = -1;
	stack = malloc(sizeof(t_list) * 1);
	if (!stack)
		return (NULL);
	stack->next = NULL;
	while (tab[++i])
	{
		tmp = ft_lstnew(&tab[i], sizeof(tab[i]));
		if (!tmp)
		{
			ft_lstclear(&stack, free);
			return (NULL);
		}
	}
	return (stack);
}
