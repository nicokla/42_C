/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:19:49 by nicolas           #+#    #+#             */
/*   Updated: 2019/11/04 18:25:44 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	try_free(void **ppointer)
{
	if (ppointer == NULL)
		return ;
	if (*ppointer != NULL)
	{
		free(*ppointer);
		*ppointer = NULL;
	}
}

void	try_free_all(t_params *p)
{
	int i;

	i = -1;
	while (++i < 5)
		if (p->mlx.mlx_ptr && p->textures[i].data)
			(void)mlx_destroy_image(p->mlx.mlx_ptr, p->textures[i].img_ptr);
	if (p->mlx.mlx_ptr && p->mlx.img.data)
		(void)mlx_destroy_image(p->mlx.mlx_ptr, p->mlx.img.img_ptr);
	if (p->mlx.mlx_ptr)
		if (((t_mlx_ptr*)p->mlx.mlx_ptr)->font)
			(void)mlx_destroy_image(p->mlx.mlx_ptr,
				((t_mlx_ptr*)p->mlx.mlx_ptr)->font);
	if (p->mlx.mlx_ptr && p->mlx.win)
		(void)mlx_destroy_window(p->mlx.mlx_ptr, p->mlx.win);
	try_free(&p->mlx.mlx_ptr);
	ft_lstclear(&p->map2);
	free_static_tab((void**)p->map, p->map_height);
	try_free((void**)&p->table_sin);
	try_free((void**)&p->table_cos);
}
