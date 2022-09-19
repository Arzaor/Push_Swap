/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:25:56 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/19 16:16:17 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_2d_pile(char **argv, int argc, t_pile *pile)
{
	int	i;

	i = argc - 1;
	while (i >= 0)
		push(&pile, ft_atoi(argv[i--]));
}

t_pile	*fill_1d_pile(int *tab_pile, int length, t_pile *pile)
{
	int	i;

	i = length - 1;
	while (i >= 0)
		push(&pile, tab_pile[i--]);
	return (pile);
}

void	treatment(char **argv, int argc)
{
	t_pile	*pileA;
	t_pile	*pileB;

	pileA = NULL;
	pileB = NULL;
	fill_2d_pile(argv, argc, pileA);
	view(pileA);
	/*
	if (length(pileA) == 2)
		swap(pileA, 1);
	else if (length(pileA) == 3)
	{
		if (pileA->nombre > pileA->prec->nombre && pileA->nombre < pileA->prec->prec->nombre)
			swap(pileA, 1);
	}*/
	clear(&pileA);
	clear(&pileB);
}