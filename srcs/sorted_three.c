/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:38:30 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/26 03:57:25 by jbarette         ###   ########.fr       */
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
	if (first > second && first > third && second < first && second > third && third < first && third < second)
	{
		rotate(pile, 1);
		swap(pile, 1);
	}
	else if (first > second && first < third && second < first && second < third && third > first && third > second)
		swap(pile, 1);
	else if (first > second && first > third && second < first && second < third && third < first && third > second)
		rotate(pile, 1);
	else if (first < second && first > third && second > first && second > third && third < first && third < second)
		reverse_rotate(pile, 0);
	else if (first < second && first < third && second > first && second > third && third > first && third < second)
	{
		reverse_rotate(pile, 1);
		swap(pile, 1);
	}
}