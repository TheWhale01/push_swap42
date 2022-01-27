/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:26:35 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/27 23:29:59 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_pos
{
	int	stack_a;
	int	stack_b;
}	t_pos;

int		abs(int n);
int		tablen(char **tab);
int		check_sorted(t_list **lst);

void	exit_with_msg(char *str, char **tab);
void	non_lis_to_b(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b, char *str);
void	pb(t_list **a, t_list **b, char *str);
void	rr(t_list **a, t_list **b, char *str);
void	ss(t_list **a, t_list **b, char *str);
void	rrr(t_list **a, t_list **b, char *str);
void	solve(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack, t_list **none, char *str);
void	sb(t_list **stack, t_list **none, char *str);
void	ra(t_list **stack, t_list **none, char *str);
void	rb(t_list **stack, t_list **none, char *str);
void	rra(t_list **stack, t_list **none, char *str);
void	rrb(t_list **stack, t_list **none, char *str);

void	*free_tab(char **tab);
void	*free_lst(t_list **lst);

t_list	*stack_init(char **tab);
t_list	*pop_top(t_list **stack);
t_list	*pop_bottom(t_list	**stack);
t_list	*cost(t_pos *pos, t_list *stack_a, t_list *stack_b);

char	**check(int ac, char **av);

/* ---- TO REMOVE ---- */

void	display_lst(t_list *stack);

#endif
