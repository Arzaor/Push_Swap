/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:31:20 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/11 10:29:39 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_mediane(t_liste *pile_a, int size)
{
	int	*cpy_tab;
	int	*sorted_tab;
	int	quarter;
	int	mid;

	quarter = 0;
	mid = 0;
	cpy_tab = cpy_pile(pile_a);
	sorted_tab = sort_tab(cpy_tab, size);
	if (size <= 100)
		quarter = size / 2;
	else
		quarter = size / 4;
	if (size % 2)
		mid = sorted_tab[quarter];
	else
		mid = sorted_tab[quarter - 1];
	free(cpy_tab);
	return (mid);
}

void	created_group_pile_a(t_liste *pile_a, t_liste *pile_b)
{
	int	mid;
	int	size;
	int	i;

	mid = 0;
	size = length(pile_a);
	i = 0;
	while (size > 3)
	{
		mid = find_mediane(pile_a, size);
		while (i < size)
		{
			if (mid > pile_a->first->number)
				push(pile_a, pile_b, 0);
			else
				rotate(pile_a, 1);
			i++;
		}
		i = 0;
		size = length(pile_a);
	}
}

static void	big_sort(t_liste *pile_a, t_liste *pile_b, int pos_max)
{
	if (pos_max <= length(pile_b) / 2)
	{
		while (pos_max > 0)
		{
			rotate(pile_b, 0);
			pos_max--;
		}
	}
	else
	{
		pos_max = length(pile_b) - pos_max;
		while (pos_max > 0)
		{
			reverse_rotate(pile_b, 0);
			pos_max--;
		}
	}
	push(pile_a, pile_b, 1);
}

void	sorted(t_liste *pile_a, t_liste *pile_b)
{
	int	*cpy_tab;
	int	*sorted_tab;
	int	pos_max;

	cpy_tab = NULL;
	sorted_tab = NULL;
	pos_max = 0;
	created_group_pile_a(pile_a, pile_b);
	if (length(pile_a) == 2)
		sorted_two(pile_a, 1);
	else if (length(pile_a) == 3)
		sorted_three(pile_a);
	while (length(pile_b) > 0)
	{
		cpy_tab = cpy_pile(pile_b);
		sorted_tab = sort_tab(cpy_tab, length(pile_b));
		pos_max = search_position(pile_b, sorted_tab[length(pile_b) - 1]);
		big_sort(pile_a, pile_b, pos_max);
		free(cpy_tab);
	}
}
