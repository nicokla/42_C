/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:56:57 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/31 16:41:58 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_right(t_params *p)
{
	p->angle -= 2.0f / 180.0f * M_PI;
	update_orientation(p);
}

void	turn_left(t_params *p)
{
	p->angle += 2.0f / 180.0f * M_PI;
	update_orientation(p);
}

void	go_forward(t_params *p)
{
	p->x += p->dx * 0.1;
	p->y += p->dy * 0.1;
	if (p->x < 1.0001)
		p->x = 1.0001;
	if (p->y < 1.0001)
		p->y = 1.0001;
	if (p->x > (p->map_width - 1.0001))
		p->x = (p->map_width - 1.0001);
	if (p->y > (p->map_height - 1.0001))
		p->y = (p->map_height - 1.0001);
}

void	go_backward(t_params *p)
{
	p->x -= p->dx * 0.1;
	p->y -= p->dy * 0.1;
	if (p->x < 1.0001)
		p->x = 1.0001;
	if (p->y < 1.0001)
		p->y = 1.0001;
	if (p->x > (p->map_width - 1.0001))
		p->x = (p->map_width - 1.0001);
	if (p->y > (p->map_height - 1.0001))
		p->y = (p->map_height - 1.0001);
}
