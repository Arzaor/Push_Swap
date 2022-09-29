/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:34:31 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/29 13:48:17 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**delete_element_tab(char **argv, int argc, int pos)
{
	int i;

	i = pos;
	while (i < argc)
	{
		argv[i] = argv[i + 1];
		i++;
	}
	return (argv);
}

int	*cpy_pile(t_liste *pile)
{
	int 		length_pile;
	int			*tab_pile;
	int			i;
	t_element	*now;

	length_pile = length(pile);
	tab_pile = malloc(sizeof(int) * length_pile);
	i = 0;
	now = pile->first;
	while (i < length_pile)
	{
		tab_pile[i] = now->number;
		now  = now->next;
		i++;
	}
	return (tab_pile);
}

int	*created_tab_by_group(t_liste *pile, int group)
{
	int 		length_pile;
	int			*tab_pile;
	int			i;
	t_element	*now;

	length_pile = length_by_group(pile, group);
	tab_pile = malloc(sizeof(int) * length_pile);
	i = 0;
	now = pile->first;
	while (i < length_pile)
	{
		if (group == now->group)
			tab_pile[i] = now->number;
		now  = now->next;
		i++;
	}
	return (tab_pile);
}

int	*sort_tab(int *pile_tab, int size)
{
	int x;
	int	y;
	int	tmp;

	x = 0;
	while (x <= size - 1)
	{
		y = 0;
		while (y <= size - 2)
		{
			if (pile_tab[y] > pile_tab[x])
			{
				tmp = pile_tab[x];
				pile_tab[x] = pile_tab[y];
				pile_tab[y] = tmp;
			}
			y++;
		}
		x++;
	}
	return (pile_tab);
}

int	order(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i + 1])
		{
			if (tab[i + 1] < tab[i])
				return (0);
		}
		i++;
	}
	return (1);
}