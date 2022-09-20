/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:51:26 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/20 15:13:17 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_liste *pile, int opt)
{
	int			*tab;
	int			tmp;
	t_element	*now;
	int			i;

	tab = malloc(sizeof(int) * length(pile));
	tmp = pile->first->number;
	now = pile->first->next;
	i = 0;
	while (i < length(pile) - 1)
	{
		tab[i] = now->number;
		now = now->next;
		i++;
	}
	tab[i] = tmp;
	clear(pile);
	fill_1d_pile(tab, length(pile), pile);
	if (opt)
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}