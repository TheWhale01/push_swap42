/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:42:45 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/13 22:30:42 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**tab;
	t_list	*a;

	tab = check(ac, av);
	a = stack_init(tab);
	if (!a)
		return (0);
	push_min_top(&a);
	display_lst(a);
	free_lst(&a);
	return (0);
}
