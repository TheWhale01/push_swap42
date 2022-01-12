#include <stdio.h>
#include "push_swap.h"

void	display(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
		printf("%d ", tab[i++]);
	printf("\n");
}

void	sort(int n)
{
	int	i;
	int	tab[NB_OPS];

	i = -1;
	while (++i < n)
		tab[i] = 0;
	while (tab[0] < NB_OPS)
	{
		display(tab, n);
		tab[n - 1]++;
		i = 0;
		while (++i < n)
		{
			if (tab[i] > 10)
			{
				tab[i] = 0;
				tab[i - 1]++;
			}
		}
	}
}

int	main(void)
{
	int	i;

	i = 10;
	sort(i);
	return (0);
}
