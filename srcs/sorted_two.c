/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:38:30 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/26 13:47:31 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_two(t_liste *pile, int opt)
{
	if (pile->first->number > pile->first->next->number)
		swap(pile, opt);
}