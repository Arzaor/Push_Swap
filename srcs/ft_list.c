/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:13:44 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/12 01:18:22 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*init()
{
    t_pile *pile = malloc(sizeof(*pile));
    t_element *element = malloc(sizeof(*element));

    if (pile == NULL || element == NULL)
        exit(EXIT_FAILURE);
    element->content = 0;
    element->next = NULL;
    pile->first = element;
    return (pile);
}

t_pile	*new_element(t_pile *pile, int content)
{
    t_element *new = malloc(sizeof(*new));
    if (pile == NULL || new == NULL)
        exit(EXIT_FAILURE);
    new->content = content;
    new->next = pile->first;
    pile->first = new;
	return (pile);
}

void	show_list(t_pile *pile)
{
    if (pile == NULL)
        exit(EXIT_FAILURE);
    t_element *now = pile->first;
    while (now != NULL)
    {
        printf("%d\n", now->content);
        now = now->next;
    }
}