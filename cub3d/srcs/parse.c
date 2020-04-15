/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:44:15 by nicolas           #+#    #+#             */
/*   Updated: 2019/11/04 15:00:53 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		count_words(char **words)
{
	int i;

	i = 0;
	while (words[i] != NULL)
		i++;
	return (i);
}

void	free_words(char **words)
{
	int j;

	if (words == NULL)
		return ;
	j = 0;
	while (words[j])
		free(words[j++]);
	free(words);
}

int		parse_sub_texture(t_params *p, char **words, int index)
{
	if (count_words(words) != 2)
		return (print_error(p, "Should give exactly one file for texture."));
	p->textures[index].img_ptr =
		mlx_xpm_file_to_image(&(p->mlx), words[1],
			&p->textures[index].width,
			&p->textures[index].height);
	if (p->textures[index].img_ptr == NULL)
		return (print_error(p, "texture file not found"));
	p->textures[index].data =
		(int *)mlx_get_data_addr(p->textures[index].img_ptr,
			&p->textures[index].bpp, &p->textures[index].size_l,
			&p->textures[index].endian);
	p->textures[index].bpp /= 8;
	return (EXIT_SUCCESS);
}

int		parse_sub_resolution(t_params *p, char **words)
{
	int		i;
	double	dtheta;
	double	theta0;

	if (count_words(words) != 3)
		return (print_error(p, "resolution number of argument should be 2."));
	p->win_width = ft_atoi(words[1]);
	p->win_height = ft_atoi(words[2]);
	if (!(p->win_width > 1 && p->win_height > 1))
		return (print_error(p, "window dimensions should be higher than 1"));
	if (!(p->table_sin = malloc(sizeof(double) * p->win_width)))
		return (EXIT_FAILURE);
	if (!(p->table_cos = malloc(sizeof(double) * p->win_width)))
		return (EXIT_FAILURE);
	i = -1;
	dtheta = -M_PI / 3 / (p->win_width - 1);
	theta0 = M_PI / 6;
	while (++i < p->win_width)
	{
		p->table_sin[i] = sin(theta0);
		p->table_cos[i] = cos(theta0);
		theta0 += dtheta;
	}
	return (EXIT_SUCCESS);
}

int		parse_sub_color(t_params *p, char **words, int floor_or_ceiling)
{
	char	**words2;
	t_color	*pc;

	if (count_words(words) != 2)
		return (print_error(p, "Wrong format of a color (floor or ceiling)."));
	words2 = ft_split(words[1], ',');
	if (count_words(words2) != 3)
	{
		free_words(words2);
		return (print_error(p, "Wrong format of a color (floor or ceiling)."));
	}
	pc = &p->colors[floor_or_ceiling];
	pc->r = ft_atoi(words2[0]);
	pc->g = ft_atoi(words2[1]);
	pc->b = ft_atoi(words2[2]);
	p->colors_int[floor_or_ceiling] = pc->b;
	p->colors_int[floor_or_ceiling] += (pc->g << 8);
	p->colors_int[floor_or_ceiling] += (pc->r << 16);
	free_words(words2);
	if (pc->r < 0 || pc->r > 255 ||
		pc->g < 0 || pc->g > 255 ||
		pc->b < 0 || pc->b > 255)
		return (print_error(p, "color component not in range 0-255."));
	return (EXIT_SUCCESS);
}
