/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 21:01:39 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/19 22:06:27 by hubretec         ###   ########.fr       */
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

void	check_stack(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	if (!stack || !stack->stack)
		exit_with_msg("Error\n");
	while (++i < stack->len)
	{
		j = i;
		while (++j < stack->len)
		{
			if (stack->stack[i] == stack->stack[j])
			{
				free_stack(stack);
				exit_with_msg("Error\n");
			}
		}
	}
}

t_stack	*stack_init(int ac, char **av)
{
	int				i;
	long long int	n;
	t_stack			*stack;

	stack = malloc(sizeof(t_stack) * 1);
	stack->stack = malloc(sizeof(int) * (ac - 1));
	if (!stack || !stack->stack)
		return (free_stack(stack));
	i = 0;
	while (++i < ac)
	{
		n = ft_atoll(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (free_stack(stack));
		stack->stack[i - 1] = n;
	}
	stack->len = ac - 1;
	check_stack(stack);
	return (stack);
}
