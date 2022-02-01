/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:50:55 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/01 19:34:40 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = stack_init(check(ac, av));
	if (!a)
		return (0);
	if (checker(&a, &b))
		ft_putendl_fd("OK", STDOUT);
	else
		ft_putendl_fd("KO", STDOUT);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
