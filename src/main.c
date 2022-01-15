/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:42:45 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/15 11:30:34 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**tab;
	t_list	*a;
	t_list	*tmp;

	tab = check(ac, av);
	a = stack_init(tab);
	if (!a)
		return (0);
	tmp = push_min_top(&a);
	printf("lol\n");
	display_lst(a);
	free_lst(&a);
	return (0);
}
