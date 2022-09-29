/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_hundred.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:31:20 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/29 15:32:22 by jbarette         ###   ########.fr       */
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
				rotate(pileA, 1, 0);
			i++;
		}
		i = 0;
		group++;
		free(sorted_tab);
		size = length(pileA);
	}
	return (group);
}

void	sorted_hundred(t_liste *pileA, t_liste *pileB)
{
	int group;
	int	sizeg;
	int mid;
	int	*tab;
	int	*tab_by_group;
	t_element *now;
	int	 count;

	group = created_group_pileA(pileA, pileB);
	sizeg = 0;
	mid = 0;
	tab_by_group = 0;
	tab = cpy_pile(pileA);
	now = NULL;
	count = 0;
	if (!(order(tab, length(pileA))))
	{
		if (length(pileA) == 2)
			sorted_two(pileA, 1);
		else
			sorted_three(pileA);
	}
	while (group > 0)
	{
		sizeg = length_by_group(pileB, group);
		if (sizeg == 1)
			push(pileA, pileB, 1);
		else if (sizeg > 2)
		{
			tab_by_group = created_tab_by_group(pileB, group);
			mid = tab_by_group[(sizeg / 2)];
			while (sizeg > 2)
			{
				now = pileB->first;
				while (now != NULL)
				{
					if (mid < now->number)
					{
						now->group = now->group + 1;
						count++;
						printf("%d\n", count);
					}
					else
						rotate(pileB, 0, now->group);
					now = now->next;
				}
				sizeg -= count;
			}
			group++;
		}
		else
		{
			if (pileB->first->number < pileB->first->next->number)
				swap(pileB, 0);
			while (sizeg > 0)
			{
				push(pileA, pileB, 1);
				sizeg--;
			}
		}
		group--;
	}
	free(tab);
	free(tab_by_group);
	// if (length(pileA) == 2)
	// 	sorted_two(pileA, 1);
	// else if (length(pileA) == 3)
	// 	sorted_three(pileA);
	// while (group > 0)
	// {
	// 	while (search_max(pileB, pileB->first->number))
	// 	 	push(pileA, pileB, 0);
	// 	if (length_by_group(pileB, group) == 2)
	// 		swap(pileB, 0);
	// 	else if (length_by_group(pileB, group) > 3)
	// 		group = created_group_pileB(pileB, pileA);
	// 	group--;
	// }
	view(pileA);
	printf("\n\n");
	view(pileB);
}