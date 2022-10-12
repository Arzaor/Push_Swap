/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:33:55 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/12 09:34:10 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_liste *pileA, t_liste *pileB, int opt)
{
	if (opt)
	{
		push_to_list(pileA, pop(pileB));
		ft_putstr_fd("pa\n", 1);
	}
	else
	{
		push_to_list(pileB, pop(pileA));
		ft_putstr_fd("pb\n", 1);
	}
}
