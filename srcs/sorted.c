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

void	created_group_pileA(t_liste *pileA, t_liste *pileB)
{
	int	*cpy_tab;
	int			*sorted_tab;
	int			mid;
	int			size;
	int			i;
	int			group;

	cpy_tab = NULL;
	sorted_tab = NULL;
	mid = 0;
	size = length(pileA);
	i = 0;
	group = 1;
	while (size > 3)
	{
		cpy_tab = cpy_pile(pileA);
		sorted_tab = sort_tab(cpy_tab, size);
		if (size % 2)
			mid = sorted_tab[(size / 2)];
		else
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
		free(cpy_tab);
		size = length(pileA);
	}
}

void	sorted(t_liste *pileA, t_liste *pileB)
{
	int	*cpy_tab;
	int	*sorted_tab;
	int	pos_max;

	cpy_tab = NULL;
	sorted_tab = NULL;
	pos_max = 0;
	created_group_pileA(pileA, pileB);
	if (length(pileA) == 2)
		sorted_two(pileA, 1);
	else if (length(pileA) == 3)
		sorted_three(pileA);
	while (length(pileB) > 0)
	{
		cpy_tab = cpy_pile(pileB);
		sorted_tab = sort_tab(cpy_tab, length(pileB));
		pos_max = search_position(pileB, sorted_tab[length(pileB) - 1]);
		if (pos_max <= length(pileB) / 2)
		{
			while (pos_max > 0)
			{
				rotate(pileB, 0, 0);
				pos_max--;
			}
		}
		else
		{
			pos_max = length(pileB) - pos_max;
			while (pos_max > 0)
			{
				reverse_rotate(pileB, 0);
				pos_max--;
			}
		}
		push(pileA, pileB, 1);
		free(cpy_tab);
	}
	// view(pileA);
	// printf("\n\n");
	// view(pileB);
}