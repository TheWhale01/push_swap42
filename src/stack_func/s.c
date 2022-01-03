/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:19:54 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/28 19:27:31 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sa(t_stack *a, t_stack *none)
{
	(void)none;
	if (a->len < 2)
		return ;
	ft_swap(&a->stack[a->len - 1], &a->stack[a->len - 2]);
}

void	sb(t_stack *none, t_stack *b)
{
	(void)none;
	if (b->len < 2)
		return ;
	ft_swap(&b->stack[b->len - 1], &b->stack[b->len - 2]);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, b);
	sb(a, b);
}
