/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_hundred.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:31:20 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/10 14:29:02 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	created_group_pileA(t_liste *pileA, t_liste *pileB)
{
	int			*sorted_tab;
	int			mid;
	int			size;
	int			i;
	int			group;
	t_element	*now;

	sorted_tab = NULL;
	mid = 0;
	size = length(pileA);
	i = 0;
	group = 1;
	now = NULL;
	while (size > 3)
	{
		sorted_tab = sort_tab(cpy_pile(pileA), size);
		mid = sorted_tab[(size / 2) - 1];
		while (i < size)
		{
			if (mid > pileA->first->number)
			{
				push(pileA, pileB, 0);
				pileB->first->group = group;
			}
			else
				rotate(pileA, 1, 1);
			i++;
		}
		i = 0;
		group++;
		free(sorted_tab);
		size = length(pileA);
	}
	return (group - 1);
}

void	sorted_hundred(t_liste *pileA, t_liste *pileB)
{
	int			group;
	t_element	*now;
	int			*sorted_tab;
	int			number_max;
	int			pos_max;
	int			size;

	group = created_group_pileA(pileA, pileB);
	now = NULL;
	sorted_tab = NULL;
	number_max = 0;
	pos_max = 0;
	size = length(pileB);
	if (length(pileA) == 2)
		sorted_two(pileA, 1);
	else
		sorted_three(pileA);
	while (length(pileB) > 0)
	{
		sorted_tab = sort_tab(cpy_pile(pileB), size);
		number_max = sorted_tab[size - 1];
		pos_max = search_position(pileB, number_max);
		if (pos_max <= size / 2)
		{
			while (pos_max > 0)
			{
				rotate(pileB, 0, 0);
				pos_max--;
			}
		}
		else
		{
			pos_max = size - pos_max;
			while (pos_max > 0)
			{
				reverse_rotate(pileB, 0);
				pos_max--;
			}
		}
		push(pileA, pileB, 1);
		size = length(pileB);
	}
}