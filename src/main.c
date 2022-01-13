/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:42:45 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/13 15:32:00 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*lst;
	char	**tab;

	tab = check(ac, av);
	lst = stack_init(tab);
	if (!lst)
		return (0);
	return (0);
}
