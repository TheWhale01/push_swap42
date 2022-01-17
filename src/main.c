/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:42:45 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/17 11:19:03 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**tab;
	t_list	*a;
	t_list	*tmp;
	t_list	*lis;

	tab = check(ac, av);
	a = stack_init(tab);
	if (!a)
		return (0);
	tmp = push_min_top(&a);
	display_lst(tmp);
	lis = get_lis(tmp);
	display_lst(lis);
	ft_lstclear(&a, free);
	ft_lstclear(&tmp, free);
	return (0);
}
