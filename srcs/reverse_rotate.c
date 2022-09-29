/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:51:26 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/29 15:05:36 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_liste *pile, int opt)
{
	int			size;
	int			*old_tab;
	int			*new_tab;
	t_element	*now;
	int			i;
	
	size = length(pile);
	old_tab = cpy_pile(pile);
	new_tab = malloc(sizeof(int) * size + 1);
	now = pile->first;
	new_tab[0] = old_tab[size - 1];
	i = 1;
	while (i <= size)
	{
		new_tab[i] = now->number;
		now = now->next;
		i++;
	}
	clear(pile);
	fill_1d_pile(new_tab, size, pile, 0);
	free(old_tab);
	free(new_tab);
	if (opt)
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}