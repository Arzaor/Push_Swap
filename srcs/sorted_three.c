/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:38:30 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/12 12:40:47 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_three(t_liste *pile)
{
	int	f;
	int	s;
	int	t;

	f = pile->first->number;
	s = pile->first->next->number;
	t = pile->first->next->next->number;
	if (f > s && f > t && s < f && s > t && t < f && t < s)
	{
		rotate(pile, 1);
		swap(pile, 1);
	}
	else if (f > s && f < t && s < f && s < t && t > f && t > s)
		swap(pile, 1);
	else if (f > s && f > t && s < f && s < t && t < f && t > s)
		rotate(pile, 1);
	else if (f < s && f > t && s > f && s > t && t < f && t < s)
		reverse_rotate(pile, 1);
	else if (f < s && f < t && s > f && s > t && t > f && t < s)
	{
		reverse_rotate(pile, 1);
		swap(pile, 1);
	}
}
