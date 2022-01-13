/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:49:56 by hubretec          #+#    #+#             */
/*   Updated: 2022/01/13 15:32:48 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	display(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_putendl_fd(tab[i++], STDOUT);
}

char	**ft_tabadd(char **tab, char **add)
{
	int		i;
	int		j;
	char	**result;

	result = malloc(sizeof(char *) * (tablen(add) + tablen(tab) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (tab && tab[i])
	{
		result[i] = ft_strdup(tab[i]);
		if (!result[i++])
			return (free_tab(result));
	}
	j = -1;
	while (add[++j])
	{
		result[i] = ft_strdup(add[j]);
		if (!result[i++])
			return (free_tab(result));
	}
	free_tab(tab);
	free_tab(add);
	result[i] = NULL;
	return (result);
}

char	**get_tab(int ac, char **av)
{
	int		i;
	char	**tab;
	char	**tmp;

	i = 0;
	tab = NULL;
	while (++i < ac)
	{
		tmp = ft_split(av[i], ' ');
		//if (i == 2)
		//	tmp = NULL;
		if (!tmp)
			exit_with_msg("Memory Error.", tab);
		tab = ft_tabadd(tab, tmp);
	}
	return (tab);
}

int	check_double(char **tab)
{
	int	i;
	int	j;
	int	index1;
	int	index2;

	i = -1;
	while (tab[++i])
	{
		j = i + 1;
		index1 = 0;
		index2 = 0;
		if (tab[i][0] == '+')
			index1 = 1;
		if (tab[j] && tab[j][0] == '+')
			index2 = 1;
		while (tab[j])
			if (!ft_strcmp(&tab[i][index1], &tab[j++][index2]))
				return (1);
	}
	return (0);
}

char	**check(int ac, char **av)
{
	int		i;
	int		j;
	char	**tab;

	if (ac <= 2)
		exit(0);
	i = -1;
	tab = get_tab(ac, av);
	while (tab[++i])
	{
		j = 0;
		if (!ft_isdigit(tab[i][j]) && tab[i][j] != '-' && tab[i][j] != '+')
			exit_with_msg("Error", tab);
		else if (ft_strlen(tab[i]) == 1
			&& (tab[i][j] == '+' || tab[i][j] == '-'))
			exit_with_msg("Error", tab);
		while (tab[i][++j])
			if (!ft_isdigit(tab[i][j]))
				exit_with_msg("Error", tab);
	}
	if (check_double(tab))
		exit_with_msg("Error", tab);
	return (tab);
}