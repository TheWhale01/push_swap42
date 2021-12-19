/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:45:38 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/19 21:53:48 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

void	display(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->len)
		ft_printf("%d ", stack->stack[i]);
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (!checker(ac, av))
		return (0);
	if (!(stack = stack_init(ac, av)))
		return (0);
	display(stack);
	free_stack(stack);
	return (0);
}
