/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:35:12 by nicolas           #+#    #+#             */
/*   Updated: 2019/11/05 18:06:44 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	prepare_loop_png(t_params *p, t_libattopng **ppng, int *py)
{
	draw(p);
	mlx_put_image_to_window(p->mlx.mlx_ptr,
		p->mlx.win, p->mlx.img.img_ptr, 0, 0);
	*ppng = libattopng_new(p->win_width, p->win_height, PNG_RGBA);
	*py = 0;
}

int		save_png(t_params *p)
{
	t_libattopng	*png;
	int				x;
	int				y;
	t_color			pix;
	int				tmp;

	prepare_loop_png(p, &png, &y);
	while (y < p->win_height)
	{
		x = 0;
		while (x < p->win_width)
		{
			tmp = p->mlx.img.data[p->win_width * y + x];
			pix.r = (tmp & 0x00FF0000) >> 16;
			pix.g = (tmp & 0x0000FF00) >> 8;
			pix.b = (tmp & 0x000000FF);
			libattopng_set_pixel(png, x, y, RGB(pix.r, pix.g, pix.b));
			x++;
		}
		y++;
	}
	libattopng_save(png, "first_screen.png");
	libattopng_destroy(png);
	try_free_all(p);
	return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
	t_params	params;
	t_params	*p;
	int			fd;

	p = &params;
	init_params(p);
	if (ac != 2 && ac != 3)
		return (print_error(p, "./cub3d map_name [-save]"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (print_error(p, "map file not found."));
	(void)init_mlx(p);
	if (parse(p, fd))
		return (print_error(p, "Could not parse the map."));
	(void)init_mlx_win(p);
	if (ac == 3 && ft_strcmp(av[2], "-save") == 0)
		return (save_png(p));
	else if (ac == 3)
		return (print_error(p, "./cub3d map_name [-save]"));
	mlx_do_key_autorepeatoff(p->mlx.mlx_ptr);
	mlx_hook(p->mlx.win, 2, 1L << 0, hook_keydown, p);
	mlx_hook(p->mlx.win, 3, 1L << 1, hook_keyup, p);
	mlx_hook(p->mlx.win, 17, 0, close_win, p);
	mlx_loop_hook(p->mlx.mlx_ptr, loop_listener, p);
	mlx_loop(p->mlx.mlx_ptr);
}
