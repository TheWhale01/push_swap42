/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:01:08 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/28 17:41:49 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	exit_with_msg(char *str, char **tab)
{
	free_tab(tab);
	ft_putendl_fd(str, STDERR);
	exit(0);
}

void	*free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab && tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

void	*free_lst(t_list **lst)
{
	ft_lstclear(lst, free);
	return (NULL);
}

/* ---- TO REMOVE ---- */

void	display_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%d -> ", *(int *)tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

void	display_tab(int *tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		printf("%d ", tab[i]);
	printf("\n");
}
