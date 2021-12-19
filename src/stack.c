/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 21:01:39 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/19 21:53:21 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

void	*free_stack(t_stack *stack)
{
	free(stack->stack);
	free(stack);
	return (NULL);
}

t_stack	*stack_init(int ac, char **av)
{
	int				i;
	long long int	n;
	t_stack			*a;

	a = malloc(sizeof(t_stack) * 1);
	a->stack = malloc(sizeof(int) * (ac - 1));
	if (!a || !a->stack)
		return (free_stack(a));
	i = 0;
	while (++i < ac)
	{
		n = ft_atoll(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (free_stack(a));
		a->stack[i - 1] = n;
	}
	a->len = ac - 1;
	return (a);
}
