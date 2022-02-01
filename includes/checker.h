/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:41:33 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/01 19:36:02 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

int		check_sorted(t_list **stack);
int		checker(t_list **stack_a, t_list **stack_b);

void	rb(t_list **none, t_list **stack_b);
void	sb(t_list **none, t_list **stack_b);
void	ra(t_list **stack_a, t_list **none);
void	sa(t_list **stack_a, t_list **none);
void	rra(t_list **stack_a, t_list **none);
void	rrb(t_list **none, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

t_list	*stack_init(char **tab);
t_list	*pop_top(t_list	**stack);
t_list	*pop_bottom(t_list **stack);

char	**check(int ac, char **av);

#endif