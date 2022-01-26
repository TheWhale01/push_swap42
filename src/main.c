/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:42:45 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/26 16:32:11 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_pos	pos;

	b = NULL;
	a = stack_init(check(ac, av));
	if (!a)
		return (0);
	non_lis_to_b(&a, &b);
	ft_printf("stack a : ");
	display_lst(a);
	ft_printf("stack b : ");
	display_lst(b);
	ft_printf("smart_rotate : %d\n", smart_rotate(pos, &a, &b));
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
