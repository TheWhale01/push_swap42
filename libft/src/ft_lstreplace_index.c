/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreplace_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:49:41 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/17 13:55:38 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreplace_index(t_list *stack, t_list *new, int index)
{
	int		n;
	t_list	*tmp;

	n = 0;
	tmp = stack;
	while (tmp)
	{
		if (n++ == index)
			*(int *)tmp->content = *(int *)new->content;
		tmp = tmp->next;
	}
}
