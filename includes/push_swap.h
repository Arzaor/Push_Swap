/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:54:12 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/19 10:56:24 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_element
{
	int					content;
	struct s_element	*next;
}				t_element;

typedef struct	s_pile
{
    t_element	*first;
}				t_pile;

//FT_LIST
t_pile	*init();
t_pile	*new_element(t_pile *pile, int content);
void	show_list(t_pile *pile);

//EXIT
void	ft_exit();

//PARSING
void	parsing(char **argv, int argc);

// UTILS
char	**delete_element_tab(char **argv, int argc, int pos);

#endif