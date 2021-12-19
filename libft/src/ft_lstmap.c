/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:41:32 by hubretec          #+#    #+#             */
/*   Updated: 2021/11/24 16:06:02 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*tmp_node;

	new = 0;
	tmp = lst;
	while (tmp)
	{
		tmp_node = ft_lstnew(f(tmp->content));
		if (!tmp_node)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, tmp_node);
		tmp = tmp->next;
	}
	return (new);
}
