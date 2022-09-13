/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:54:55 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/13 14:51:25 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**tmp;

	if (argc <= 0)
		ft_exit();
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = delete_element_tab(argv, argc, 0);
	parsing(argv, argc - 1);
	while (1) ;
	return (0);
}