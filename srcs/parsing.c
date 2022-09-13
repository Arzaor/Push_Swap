/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:02:57 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/13 16:46:13 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parsing_letter(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])) && argv[i][j] != '-')
				ft_exit();
			j++;
		}
		j = 0;
		i++;
	}
}

static void	parsing_min_max(char **argv)
{
	int			i;
	long long	tmp;

	i = 0;
	tmp = 0;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_exit();
		i++;
	}
}

static void	parsing_doublon(char **argv)
{
	int			i;
	int			j;
	long long	tmp;
	long long	tmp_bis;

	i = 0;
	j = 0;
	tmp = 0;
	tmp_bis = 0;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		while (argv[j])
		{
			tmp_bis = ft_atoi(argv[j]);
			if (tmp == tmp_bis && i != j)
				ft_exit();
			j++;
		}
		j = 0;
		i++;
	}
}

static void	fill_pileA(char **argv, int argc, t_pile *pile)
{
	int	i;

	i = argc - 1;
	while (i >= 0)
		pile = new_element(pile, ft_atoi(argv[i--]));
}

void	parsing(char **argv, int argc)
{
	t_pile	*pileA;

	pileA = init();
	parsing_letter(argv);
	parsing_min_max(argv);
	parsing_doublon(argv);
	// fill_pileA(argv, argc, pileA);
	show_list(pileA);
	free(pileA);
}