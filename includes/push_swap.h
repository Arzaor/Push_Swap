/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:54:12 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/19 16:16:09 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_pile
{
	int				nombre;
	struct s_pile	*prec;
}				t_pile;

//FT_LIST
void	push(t_pile **p, int value);
int		pop(t_pile **p);
void	clear(t_pile **p);
int		length(t_pile *p);
void	view(t_pile *p);

//EXIT
void	ft_exit();

//PARSING
void	parsing(char **argv, int argc);

// TREATMENT_PILE
void	treatment(char **argv, int argc);
void	fill_2d_pile(char **argv, int argc, t_pile *pile);
t_pile	*fill_1d_pile(int *tab_pile, int argc, t_pile *pile);

// SWAP
t_pile	*swap(t_pile *pile, int opt);
void	swap_ss(t_pile *pileA, t_pile *pileB);

// PUSH
void	push_b(t_pile *pileA, t_pile *pileB);

// UTILS
char	**delete_element_tab(char **argv, int argc, int pos);
int		*cpy_pile(t_pile *pile);

#endif