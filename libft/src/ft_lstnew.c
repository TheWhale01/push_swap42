/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:07:08 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/18 16:53:54 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content, size_t size)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list) * 1);
	if (!node)
		return (NULL);
	node->content = malloc(size);
	if (!node->content)
	{
		free(node);
		return (NULL);
	}
	ft_memcpy(node->content, content, size);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
