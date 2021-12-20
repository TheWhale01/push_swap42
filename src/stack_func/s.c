/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s .c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:19:54 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/20 12:33:14 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sa_b(t_stack *stack)
{
	ft_swap(&stack->stack[stack->len - 1], &stack->stack[stack->len - 2]);
}

void	ss(t_stack *a, t_stack *b)
{
	sa_b(a);
	sa_b(b);
}
