/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:23:41 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/31 16:40:22 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_params *p, t_ray *pray)
{
	pray->x = (int)p->x;
	pray->y = (int)p->y;
	pray->stepx = (p->dx2 >= 0 ? 1 : -1);
	pray->stepy = (p->dy2 >= 0 ? 1 : -1);
	pray->step_distx = sqrt(1 + (p->dy2 * p->dy2) / (p->dx2 * p->dx2));
	pray->step_disty = sqrt(1 + (p->dx2 * p->dx2) / (p->dy2 * p->dy2));
	pray->distx = pray->step_distx *
		(p->dx2 >= 0 ? 1. - (p->x - (double)pray->x) :
		(p->x - (double)pray->x));
	pray->disty = pray->step_disty *
		(p->dy2 >= 0 ? 1. - (p->y - (double)pray->y) :
		(p->y - (double)pray->y));
	pray->vert = (pray->distx >= pray->disty);
	pray->lst_objects = ft_lstnew();
}

void	*newobj(t_params *p, int x, int y)
{
	t_object *pobj;

	pobj = malloc(sizeof(t_object));
	if (pobj == NULL)
		return (NULL);
	pobj->a = (double)x + 0.5;
	pobj->b = (double)y + 0.5;
	pobj->dist = dist(p->x, p->y, pobj->a, pobj->b);
	pobj->angle = asin(((pobj->a - p->x) * p->dy2 * -1 +
						(pobj->b - p->y) * p->dx2) / pobj->dist);
	pobj->pos = 0.5 + pobj->dist * tan(pobj->angle);
	return ((void*)pobj);
}

void	compute_ray(t_params *p, t_ray *pray)
{
	int	i;

	i = -1;
	while (++i < 100)
	{
		if (pray->distx < pray->disty)
		{
			pray->vert = 0;
			pray->x += pray->stepx;
			if (p->map[pray->y][pray->x] != '1')
				pray->distx += pray->step_distx;
		}
		else
		{
			pray->vert = 1;
			pray->y += pray->stepy;
			if (p->map[pray->y][pray->x] != '1')
				pray->disty += pray->step_disty;
		}
		if (p->map[pray->y][pray->x] == '2')
			ft_lstadd_front(pray->lst_objects, newobj(p, pray->x, pray->y));
		else if (p->map[pray->y][pray->x] == '1')
			break ;
	}
}
