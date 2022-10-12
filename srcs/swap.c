/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:31:14 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/12 09:31:08 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_liste *pile, int opt)
{
	int			tmp;

	tmp = pile->first->number;
	pile->first->number = pile->first->next->number;
	pile->first->next->number = tmp;
	if (opt)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	swap_ss(t_liste *pileA, t_liste *pileB)
{
	swap(pileA, 1);
	swap(pileB, 0);
}
