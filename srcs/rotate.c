/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:51:26 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/22 15:32:32 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_liste *pile, int opt)
{
	int			size;
	int			*tab;
	int			tmp;
	t_element	*now;
	int			i;
	
	size = length(pile);
	tab = malloc(sizeof(int) * size + 1);
	tmp = pile->first->number;
	now = pile->first->next;
	i = 0;
	while (i < size)
	{
		tab[i] = now->number;
		now = now->next;
		i++;
	}
	tab[i - 1] = tmp;
	clear(pile);
	fill_1d_pile(tab, size, pile);
	free(tab);
	if (opt)
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}