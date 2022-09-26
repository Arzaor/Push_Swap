/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_hundred.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:31:20 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/26 15:46:40 by jbarette         ###   ########.fr       */
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
		printf("%d\n", mid);
		while (i < size)
		{
			if (mid >= pileA->first->number)
			{
				push(pileA, pileB, 0);
				pileB->first->group = group;
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
	return (group - 1);
}

void	sorted_hundred(t_liste *pileA, t_liste *pileB)
{
	int group;

	group = created_group_pileA(pileA, pileB);
	if (length(pileA) == 2)
		sorted_two(pileA, 1);
	else if (length(pileA) == 3)
		sorted_three(pileA);
	while (group > 0)
	{
		while (search_max(pileB, pileB->first->number))
		 	push(pileA, pileB, 0);
		if (length_by_group(pileB, group) == 2)
			swap(pileB, 0);
		else if (length_by_group(pileB, group) > 3)
		{
			int		*sorted_tab;
			int		mid;
		
			sorted_tab = sort_tab(cpy_pile(pileB), length(pileB));
			mid = sorted_tab[(length(pileB) / 2) - 1];
			if (mid < pileB->first->number)
				push(pileA, pileB, 1);
		}
		group--;
	}
	view(pileA);
	printf("\n\n");
	view(pileB);
}