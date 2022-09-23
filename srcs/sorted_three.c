/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:38:30 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/22 16:50:14 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_three(t_liste *pile)
{
	int	first;
	int	second;
	int	third;

	first = pile->first->number;
	second = pile->first->next->number;
	third = pile->first->next->next->number;
	if (first > second && first > third)
	{
		rotate(pile, 1);
		swap(pile, 1);
	}
	else if (first < second && first > third)
		rotate(pile, 1);
	else if (first > second && first < third)
		swap(pile, 1);
	else if (first < second && first < third)
	{
		swap(pile, 1);
		rotate(pile, 1);
	}
}