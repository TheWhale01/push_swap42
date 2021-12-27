/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:26:35 by hubretec          #+#    #+#             */
/*   Updated: 2021/12/25 20:38:41 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define NB_OPS 8

typedef struct s_stack
{
	int	*stack;
	int	len;
}	t_stack;

int		check_sorted(t_stack *stack);
int		solver(t_stack *a, t_stack *b);
int		solver(t_stack *a, t_stack *b);

void	exit_with_msg(char *str);
void	checker(int ac, char **av);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	sa_b(t_stack *stack, t_stack *none);
void	ra_b(t_stack *stack, t_stack *none);
void	rra_b(t_stack *stack, t_stack *none);

void	*free_stack(t_stack *stack);

t_stack	*stack_init(int ac, char **av);

#endif
