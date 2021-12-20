/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:45:38 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/20 16:45:00 by hubretec         ###   ########.fr       */
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
	t_stack	*a;
	t_stack	*b;

	checker(ac, av);
	a = stack_init(ac, av);
	check_sorted(a);
	b = stack_init(1, 0);
	display(a);
	display(b);
	free_stack(a);
	free_stack(b);
	return (0);
}
