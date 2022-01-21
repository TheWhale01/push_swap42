/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:26:35 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/21 14:54:16 by hubretec         ###   ########.fr       */
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
	int	pos_a;
	int	pos_b;
}	t_pos;

int		tablen(char **tab);
int		check_sorted(t_list **lst);
int		find_index(t_list *node, t_list *stack);
int		nb_moves_in_stack(t_list *node, t_list *stack);
int		nb_moves_out_stack(t_list *node, t_list *stack);

void	sa_b(t_list **stack);
void	ra_b(t_list **stack);
void	rra_b(t_list **stack);
void	rr(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ss(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);
void	exit_with_msg(char *str, char **tab);
void	non_lis_to_b(t_list **a, t_list *tmp, t_list **b);

void	*free_tab(char **tab);
void	*free_lst(t_list **lst);

t_list	*stack_init(char **tab);
t_list	*pop_top(t_list **stack);
t_list	*pop_bottom(t_list	**stack);
t_list	*push_min_top(t_list **stack);

char	**check(int ac, char **av);

/* ---- TO REMOVE ---- */

void	display_lst(t_list *stack);
void	display_tab(int *tab, int len);
void	display_lst_rev(t_list *lst);

#endif
