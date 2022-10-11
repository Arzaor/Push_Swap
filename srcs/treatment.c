/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:25:56 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/11 10:34:42 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_2d_pile(char **argv, int argc, t_liste *pile)
{
	int	i;

	i = argc - 2;
	while (i >= 0)
	{
		push_to_list(pile, ft_atoi(argv[i--]));
		pile->first->group = 0;
	}
}

t_liste	*fill_1d_pile(int *tab_pile, int length, t_liste *pile, int group)
{
	int	i;

	i = length;
	while (i >= 0)
	{
		push_to_list(pile, tab_pile[i--]);
		pile->first->group = group;
	}
	return (pile);
}

void	treatment(char **argv, int argc, t_liste *pileA, t_liste *pileB)
{
	fill_2d_pile(argv, argc, pileA);
	sorted(pileA, pileB);
}