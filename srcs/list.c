/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:13:44 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/19 16:16:04 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_pile **p, int value)
{
	t_pile *element = malloc(sizeof(t_pile));
	if (!element)
		exit(EXIT_FAILURE);
	element->nombre = value;
	element->prec = *p;
	*p = element;
}

int	pop(t_pile **p)
{
	int		value;
	t_pile	*tmp;

	if (!*p)
		return (-1);
	tmp = (*p)->prec;
	value = (*p)->nombre;
	free(*p);
	*p = tmp;
	return value;
}

void	clear(t_pile **p)
{
	t_pile	*tmp;

	while (*p)
	{
		tmp = (*p)->prec;
		free(*p);
		*p = tmp;
	}
}

int		length(t_pile *p)
{
	int	n;

	n = 0;
	while (p)
	{
		n++;
		p = p->prec;
	}
	return n;
}

void	view(t_pile *p)
{
	while (p)
	{
		printf("%d\n", p->nombre);
		p = p->prec;
	}
}