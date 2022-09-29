/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:25:56 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/27 23:27:38 by jbarette         ###   ########.fr       */
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

void	created_index(t_liste *pile)
{
	int			*tab;
	t_element	*now;
	int			i;
	int			index;

	tab = sort_tab(cpy_pile(pile), length(pile));
	now = pile->first;
	i = 0;
	index = 1;
	while (tab[i])
	{
		while (now->next != NULL)
		{
			if (tab[i] == now->number)
				now->index = index++;
			now = now->next;
		}
		now = pile->first;
		i++;
	}
	now = pile->first;
	i = 0;
	while (now->next != NULL)
	{
		now->pos = i++;
		now = now->next;
	}
}

void	treatment(char **argv, int argc, t_liste *pileA, t_liste *pileB)
{
	fill_2d_pile(argv, argc, pileA);
	created_index(pileA);
	view(pileA);
	/*if (length(pileA) == 2)
		sorted_two(pileA, 1);
	else if (length(pileA) == 3)
		sorted_three(pileA);
	else
		sorted_hundred(pileA, pileB);*/
}