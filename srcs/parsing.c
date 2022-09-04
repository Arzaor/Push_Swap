/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:02:57 by jbarette          #+#    #+#             */
/*   Updated: 2022/07/19 23:44:12 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parsing_letter(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				ft_exit();
			j++;
		}
		j = 0;
		i++;
	}
}

static t_pile	*fill_pileA(char **argv, t_pile *pile)
{
	int	i;

	i = 1;
	while (argv[i])
		pile = new_element(pile, ft_atoi(argv[i++]));
	return (pile);
}

void	parsing(char **argv)
{
	t_pile	*pileA;

	pileA = init();
	parsing_letter(argv);
	pileA = fill_pileA(argv, pileA);
	show_list(pileA);
}