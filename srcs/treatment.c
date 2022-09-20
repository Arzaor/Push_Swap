/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:25:56 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/20 15:09:33 by jbarette         ###   ########.fr       */
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

	i = length - 1;
	while (i >= 0)
		push_to_list(pile, tab_pile[i--]);
	return (pile);
}

void	treatment(char **argv, int argc, t_liste *pileA, t_liste *pileB)
{
	fill_2d_pile(argv, argc, pileA);
	// if (length(pileA) == 2)
	//		swap(pileA, 1);
	// push(pileA, pileB, 0);
	rotate(pileA, 1);
	view(pileA);
	//printf("\n\n");
	//view(pileB);
}