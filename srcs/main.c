/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:54:55 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/12 13:18:14 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_liste	*pile_a;
	t_liste	*pile_b;

	pile_a = init();
	pile_b = init();
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
	if (parsing(argv))
		treatment(argv, argc, pile_a, pile_b);
	clear(pile_a);
	return (0);
}
