/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:54:55 by jbarette          #+#    #+#             */
/*   Updated: 2022/07/19 22:46:36 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc <= 0)
		ft_exit();
	/*else if (argc == 1)
		parsing_str(argv[2]);*/
	else
		parsing(argv);
	return (0);
}