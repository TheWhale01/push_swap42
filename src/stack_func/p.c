/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:46:28 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/20 14:24:15 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

int	*tabcpy(int *src, int *dest, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	pa(t_stack *a, t_stack *b)
{
	int	*tmp;

	if (!b->len)
		return ;
	tmp = malloc(sizeof(int) * (a->len));
	if (!tmp)
		return ;
	tmp = ft_memcpy(tmp, a->stack, a->len);
	a->stack = malloc(sizeof(int) * (a->len + 1));
	if (!a->stack)
		return ;
	a->stack = ft_memcpy(a->stack, tmp, a->len);
	free(tmp);
	a->stack[a->len] = b->stack[b->len - 1];
	b->len--;
	a->len++;
}

void	pb(t_stack *a, t_stack *b)
{
	int	*tmp;

	if (!a->len)
		return ;
	tmp = malloc(sizeof(int) * (b->len));
	if (!tmp)
		return ;
	tmp = tabcpy(b->stack, tmp, b->len);
	b->stack = malloc(sizeof(int) * (b->len + 1));
	if (!b->stack)
		return ;
	b->stack = tabcpy(tmp, b->stack, b->len);
	free(tmp);
	b->stack[b->len] = a->stack[a->len - 1];
	a->len--;
	b->len++;
}
