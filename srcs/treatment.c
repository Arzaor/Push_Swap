/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:25:56 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/26 03:59:58 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_2d_pile(char **argv, int argc, t_liste *pile)
{
	int	i;

	i = argc - 2;
	while (i >= 0)
		push_to_list(pile, ft_atoi(argv[i--]));
}

t_liste	*fill_1d_pile(int *tab_pile, int length, t_liste *pile)
{
	int	i;

	i = length;
	while (i >= 0)
		push_to_list(pile, tab_pile[i--]);
	return (pile);
}

void	treatment(char **argv, int argc, t_liste *pileA, t_liste *pileB)
{
	fill_2d_pile(argv, argc, pileA);
	if (length(pileA) == 2)
	{
		if (pileA->first->number > pileA->first->next->number)
			swap(pileA, 1);
	}
	else if (length(pileA) == 3)
		sorted_three(pileA);
	else if (length(pileA) <= 100)
		small_sort(pileA);
	/*
	int	*sorted_tab;
	int	mid = 0;
	int	size = 0;
	int	i = 0;
	t_element	*now;
	size = length(pileA);
	sorted_tab = sort_tab(cpy_pile(pileA), size);
	mid = sorted_tab[(size / 2) - 1];
	while (i < size)
	{
		if (mid >= pileA->first->number)
			push(pileA, pileB, 0);
		else
			rotate(pileA, 1);
		i++;
	}
	view(pileA);
	printf("\n\n");
	view(pileB);
	*/
}