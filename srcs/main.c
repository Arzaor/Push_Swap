/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:54:55 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/10 13:20:34 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**tmp;
	t_liste	*pileA;
	t_liste	*pileB;

	pileA = init();
	pileB = init();
	if (argc <= 0)
		ft_exit();
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 0;
		while (argv[argc])
			argc++;
		argc += 1;
	}
	else
		argv = delete_element_tab(argv, argc, 0);
	parsing(argv, argc - 1);
	treatment(argv, argc, pileA, pileB);
	clear(pileA);
	return (0);
}