/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:51:35 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/31 16:41:39 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	size_vect(double x, double y)
{
	return (sqrt(x * x + y * y));
}

double	dist(double x1, double y1, double x2, double y2)
{
	return (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

void	update_orientation(t_params *p)
{
	p->dx = cos(p->angle);
	p->dy = sin(p->angle);
}

void	free_static_tab(void **tab, int size)
{
	int i;

	if (tab != NULL)
	{
		i = 0;
		while (i < size)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

double	decimal_part(double a)
{
	return (a - floor(a));
}
