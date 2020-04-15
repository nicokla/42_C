/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:58:34 by nicolas           #+#    #+#             */
/*   Updated: 2019/11/05 18:02:57 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_params(t_params *p)
{
	ft_memset(p, 0, sizeof(t_params));
	p->colors[0].r = -1;
	p->colors[1].r = -1;
}

void	recompute_angles(t_params *p)
{
	int		i;
	double	dtheta;
	double	theta0;

	i = -1;
	dtheta = -M_PI / 3 / (p->win_width - 1);
	theta0 = M_PI / 6;
	while (++i < p->win_width)
	{
		p->table_sin[i] = sin(theta0);
		p->table_cos[i] = cos(theta0);
		theta0 += dtheta;
	}
}

int		init_mlx(t_params *p)
{
	p->mlx.mlx_ptr = mlx_init();
	if (!p->mlx.mlx_ptr)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		init_mlx_win(t_params *p)
{
	p->mlx.win = mlx_new_window(p->mlx.mlx_ptr, &p->win_width,
		&p->win_height, "cub3d");
	if (!p->mlx.win)
		return (print_error(p, "Could not init mlx library."));
	recompute_angles(p);
	p->mlx.img.img_ptr =
		mlx_new_image(p->mlx.mlx_ptr, p->win_width, p->win_height);
	p->mlx.img.data = (int *)mlx_get_data_addr(p->mlx.img.img_ptr,
		&p->mlx.img.bpp, &p->mlx.img.size_l, &p->mlx.img.endian);
	p->mlx.img.bpp /= 8;
	p->mlx.img.width = p->win_width;
	p->mlx.img.height = p->win_height;
	return (EXIT_SUCCESS);
}
