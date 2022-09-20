/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:34:31 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/20 14:14:03 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**delete_element_tab(char **argv, int argc, int pos)
{
	int i;

	i = pos;
	while (i < argc)
	{
		argv[i] = argv[i + 1];
		i++;
	}
	return (argv);
}

int	*cpy_pile(t_liste *pile)
{
	int 		length_pile;
	int			*tab_pile;
	int			i;
	t_element	*now;

	length_pile = length(pile);
	tab_pile = malloc(sizeof(int) * length_pile);
	i = 0;
	now = pile->first;
	while (i < length_pile)
	{
		tab_pile[i] = now->number;
		now  = now->next;
		i++;
	}
	return (tab_pile);
}
