/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_hundred.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:31:20 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/27 23:15:32 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	created_group_pileA(t_liste *pileA, t_liste *pileB)
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
		printf("%d\n", mid);
		while (i < size)
		{
			if (mid >= pileA->first->number)
			{
				push(pileA, pileB, 0);
				// pileB->first->group = group;
			}
			else
				rotate(pileA, 1);
			i++;
		}
		i = 0;
		group++;
		free(sorted_tab);
		size = length(pileA);
	}
}

void	sorted_hundred(t_liste *pileA, t_liste *pileB)
{
	int			mediane;
	t_element	*now;

	mediane = length(pileA) / 2;
	now = pileA->first;
    while (length(pileA) > 3)
    {
		if (pileA->first->index < mediane)
			push(pileA, pileB, 0);
		else
			rotate(pileA, 1);
    }
	sorted_three(pileA);
	view(pileA);
	printf("\n\n");
	view(pileB);
}