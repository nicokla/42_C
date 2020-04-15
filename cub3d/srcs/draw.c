/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:05:32 by nicolas           #+#    #+#             */
/*   Updated: 2019/11/02 20:31:15 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_pixel(t_img *pimg, double posx, double posy)
{
	int posx2;
	int posy2;
	int width;

	width = pimg->width;
	posx2 = (int)(posx * (double)width);
	posy2 = (int)(posy * (double)pimg->height);
	return (pimg->data[width * posy2 + posx2]);
}

void	draw_column(t_params *p, int column, t_ray *pray, t_drawer *pdrawer)
{
	int			line;
	double		posy;
	double		height;

	height = p->win_height / pray->dist / p->table_cos[column];
	pdrawer->start = p->win_height / 2 - height / 2;
	pdrawer->start = fmax(pdrawer->start, 0);
	pdrawer->end = p->win_height / 2 + height / 2;
	pdrawer->end = fmin(pdrawer->end, p->win_height - 1);
	pdrawer->step_posy = 1 / ((double)(pdrawer->end - pdrawer->start));
	line = -1;
	while (++line < pdrawer->start)
		p->mlx.img.data[p->win_width * line + column] = p->colors_int[FLOOR];
	posy = 0;
	while (++line < pdrawer->end)
	{
		p->mlx.img.data[p->win_width * line + column] =
			get_pixel(&p->textures[pdrawer->index_texture], pray->pos, posy);
		posy += pdrawer->step_posy;
	}
	while (++line < p->win_height)
		p->mlx.img.data[p->win_width * line + column] = p->colors_int[CEILING];
}

void	draw_object(t_params *p, int column, char *content, t_drawer *pdrawer)
{
	t_object	*pobj;
	int			line;
	double		posy;
	double		height;
	int			pix;

	pobj = (t_object*)content;
	if (pobj->pos <= 0 || pobj->pos >= 1)
		return ;
	height = p->win_height / pobj->dist;
	pdrawer->start = p->win_height / 2 - height / 2;
	pdrawer->start = fmax(pdrawer->start, 0);
	pdrawer->end = p->win_height / 2 + height / 2;
	pdrawer->end = fmin(pdrawer->end, p->win_height - 1);
	pdrawer->step_posy = 1 / ((double)(pdrawer->end - pdrawer->start));
	line = pdrawer->start;
	posy = 0;
	while (++line < pdrawer->end)
	{
		pix = get_pixel(&p->textures[SPRITE], pobj->pos, posy);
		if (((pix >> 24) & 0xFF) < 128)
			p->mlx.img.data[p->win_width * line + column] = pix;
		posy += pdrawer->step_posy;
	}
}

void	draw_all_objects(t_params *p, int column, t_list *pobjects,
							t_drawer *pdrawer)
{
	t_elt *el;

	el = pobjects->first;
	while (el != 0)
	{
		draw_object(p, column, el->content, pdrawer);
		el = el->next;
	}
}

void	draw(t_params *p)
{
	int			column;
	t_ray		ray;
	t_drawer	drawer;

	column = -1;
	while (++column < p->win_width)
	{
		p->dx2 = p->dx * p->table_cos[column] - p->dy * p->table_sin[column];
		p->dy2 = p->dy * p->table_cos[column] + p->dx * p->table_sin[column];
		init_ray(p, &ray);
		compute_ray(p, &ray);
		ray.dist = (ray.vert ? ray.disty : ray.distx);
		ray.pos = decimal_part((ray.vert ? p->x + ray.dist * p->dx2 :
								p->y + ray.dist * p->dy2));
		if (ray.vert)
			drawer.index_texture = (p->dy2 > 0 ? SOUTH : NORTH);
		else
			drawer.index_texture = (p->dx2 > 0 ? WEST : EAST);
		draw_column(p, column, &ray, &drawer);
		draw_all_objects(p, column, ray.lst_objects, &drawer);
		ft_lstclear(ray.lst_objects);
		free(ray.lst_objects);
	}
}
