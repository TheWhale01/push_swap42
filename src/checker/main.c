/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:50:55 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/17 10:31:04 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	display_lst(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%d -> ", *(int *)tmp->content);
		tmp = tmp->next;
	}
	ft_printf("NULL\n");
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	ft_printf("nb args: %d\n", ac);
	a = stack_init(check(ac, av));
	display_lst(a);
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
