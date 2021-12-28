/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:46:28 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/28 19:06:20 by hubretec         ###   ########.fr       */
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
	if (src)
		free(src);
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
	tmp = tabcpy(a->stack, tmp, a->len);
	a->stack = malloc(sizeof(int) * (a->len + 1));
	if (!a->stack)
		return ;
	a->stack = tabcpy(tmp, a->stack, a->len);
	a->stack[a->len] = b->stack[b->len - 1];
	b->len--;
	a->len++;
	if (!b->len)
	{
		free(b->stack);
		b->stack = NULL;
	}
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
	b->stack[b->len] = a->stack[a->len - 1];
	a->len--;
	b->len++;
	if (!a->len)
	{
		free(a->stack);
		a->stack = NULL;
	}
}
