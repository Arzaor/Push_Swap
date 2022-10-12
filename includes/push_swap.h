/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:54:12 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/12 13:10:32 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_element
{
	int					number;
	struct s_element	*next;
}						t_element;

typedef struct s_liste
{
	t_element	*first;
}				t_liste;

// EXIT
void	ft_exit(void);

// FT_LIST
t_liste	*init(void);
void	push_to_list(t_liste *liste, int value);
int		pop(t_liste *liste);
void	clear(t_liste *liste);
void	view(t_liste *liste);

//PARSING
int		parsing(char **argv);

// PUSH
void	push(t_liste *pileA, t_liste *pileB, int opt);

// REVERSE_ROTATE
void	reverse_rotate(t_liste *pile, int opt);

// ROTATE
void	rotate(t_liste *pile, int opt);

// SORTED_THREE
void	sorted_three(t_liste *pile);

// SORTED_TWO
void	sorted_two(t_liste *pile, int opt);

// SORTED
void	sorted(t_liste *pileA, t_liste *pileB);

// SWAP
void	swap(t_liste *pile, int opt);
void	swap_ss(t_liste *pileA, t_liste *pileB);

// TREATMENT_PILE
void	fill_2d_pile(char **argv, int argc, t_liste *pile);
t_liste	*fill_1d_pile(int *tab_pile, int argc, t_liste *pile);
void	treatment(char **argv, int argc, t_liste *pileA, t_liste *pileB);

// UTILS
char	**delete_element_tab(char **argv, int argc, int pos);
int		*cpy_pile(t_liste *pile);
int		*sort_tab(int *pile_tab, int size);
int		search_position(t_liste *pile, int number);
int		length(t_liste *liste);

#endif