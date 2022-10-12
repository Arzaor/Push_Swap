/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:51:26 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/12 12:40:39 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*reverse_rotate_tab(t_liste *pile, int *old_tab, int size)
{
	int			i;
	int			*tab;
	t_element	*now;

	i = 1;
	tab = malloc(sizeof(int) * size + 1);
	tab[0] = old_tab[size - 1];
	now = pile->first;
	while (i <= size)
	{
		tab[i] = now->number;
		now = now->next;
		i++;
	}
	return (tab);
}

void	reverse_rotate(t_liste *pile, int opt)
{
	int			size;
	int			*old_tab;
	int			*new_tab;

	size = length(pile);
	old_tab = cpy_pile(pile);
	new_tab = reverse_rotate_tab(pile, old_tab, size);
	clear(pile);
	fill_1d_pile(new_tab, size, pile);
	free(old_tab);
	free(new_tab);
	if (opt)
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}
