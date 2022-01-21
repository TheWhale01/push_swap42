/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:42:45 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/21 14:54:34 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = stack_init(check(ac, av));
	if (!a)
		return (0);
	non_lis_to_b(&a, push_min_top(&a), &b);
	ft_printf("stack a : ");
	display_lst(a);
	ft_printf("stack b : ");
	display_lst(b);
	ft_printf("cost : %d\n", nb_moves_out_stack(b, a));
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
