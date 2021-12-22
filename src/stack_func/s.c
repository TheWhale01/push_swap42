/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:19:54 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/22 10:50:18 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sa_b(t_stack *stack, t_stack *none)
{
	(void)none;
	ft_swap(&stack->stack[stack->len - 1], &stack->stack[stack->len - 2]);
}

void	ss(t_stack *a, t_stack *b)
{
	sa_b(a, b);
	sa_b(b, a);
}
