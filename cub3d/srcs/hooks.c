/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:01:16 by nicolas           #+#    #+#             */
/*   Updated: 2019/11/04 16:26:10 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		hook_keydown(int key, t_params *p)
{
	if (key == K_ESC)
		close_win(p);
	else if (key == K_LEFT)
		p->key_left = 1;
	else if (key == K_RIGHT)
		p->key_right = 1;
	else if (key == K_UP)
		p->key_up = 1;
	else if (key == K_DOWN)
		p->key_down = 1;
	return (0);
}

int		hook_keyup(int key, t_params *p)
{
	if (key == K_LEFT)
		p->key_left = 0;
	else if (key == K_RIGHT)
		p->key_right = 0;
	else if (key == K_UP)
		p->key_up = 0;
	else if (key == K_DOWN)
		p->key_down = 0;
	return (0);
}

int		close_win(t_params *p)
{
	try_free_all(p);
	exit(EXIT_SUCCESS);
}

/*
** if (p->key_left || p->key_right || p->key_up || p->key_down)
** printf("%.3lf\t%.3lf\t\t%.3lf\t%.3lf\n", p->x, p->y, p->dx, p->dy);
*/

int		loop_listener(t_params *p)
{
	if (p->key_left)
		turn_left(p);
	if (p->key_right)
		turn_right(p);
	if (p->key_up)
		go_forward(p);
	if (p->key_down)
		go_backward(p);
	draw(p);
	mlx_put_image_to_window(p->mlx.mlx_ptr,
		p->mlx.win, p->mlx.img.img_ptr, 0, 0);
	return (0);
}
