/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:31:14 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/19 14:14:23 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*swap(t_pile *pile, int opt)
{
	int	*tab_pile;
	int	length_pile;
	int	i;
	int	tmp;

	tab_pile = cpy_pile(pile);
	length_pile = length(pile);
	tmp = tab_pile[0];
	tab_pile[0] = tab_pile[1];
	tab_pile[1] = tmp;
	clear(&pile);
	pile = fill_1d_pile(tab_pile, length_pile, pile);
	if (opt)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
	free(tab_pile);
	return (pile);
}

void	swap_ss(t_pile *pileA, t_pile *pileB)
{
	swap(pileA, 1);
	swap(pileB, 0);
}