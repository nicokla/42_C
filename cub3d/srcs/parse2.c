/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:55:34 by nicolas           #+#    #+#             */
/*   Updated: 2019/11/05 18:07:28 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_line(t_params *p, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_strchr("012ENSW", line[i]))
			return (print_error(p, "character not allowed in the map"));
		if (p->found_player && ft_strchr("ENSW", line[i]))
			return (print_error(p, "two players on the map"));
		if (ft_strchr("ENSW", line[i]))
		{
			p->found_player = *(ft_strchr("ENSW", line[i]));
			p->x = i + 0.5;
			p->y = p->map2.size + 0.5;
		}
		i++;
	}
	if (line[i - 1] != '1' || line[0] != '1')
		return (print_error(p, "map left or right side has a hole"));
	return (EXIT_SUCCESS);
}

int		parse_map(t_params *p, char *line)
{
	if (p->win_height == 0 ||
		p->win_width == 0 ||
		p->textures[0].img_ptr == NULL ||
		p->textures[1].img_ptr == NULL ||
		p->textures[2].img_ptr == NULL ||
		p->textures[3].img_ptr == NULL ||
		p->textures[4].img_ptr == NULL ||
		p->colors[0].r == -1 ||
		p->colors[1].r == -1)
		return (print_error(p, "the map needs to be the last parameter."));
	if (p->map_width == 0)
		p->map_width = ft_strlen(line);
	if (ft_strlen(line) != p->map_width)
		return (print_error(p, "map lines are not all the same length."));
	if (check_line(p, line))
		return (EXIT_FAILURE);
	ft_lstadd_front(&p->map2, line);
	return (PARSED_MAP_LINE);
}

int		check_and_store_map(t_params *p)
{
	size_t i;

	i = 0;
	while (i < p->map_width)
	{
		if (p->map2.first->content[i] != '1' ||
			p->map2.last->content[i] != '1')
			return (print_error(p, "map bottom or up wall has a hole."));
		i++;
	}
	if (!p->found_player)
		return (print_error(p, "no player found in the map."));
	if (p->found_player == 'E')
		p->angle = 0;
	else if (p->found_player == 'W')
		p->angle = M_PI;
	else if (p->found_player == 'N')
		p->angle = M_PI * 0.5;
	else if (p->found_player == 'S')
		p->angle = M_PI * 1.5;
	update_orientation(p);
	p->map = ft_lst_to_staticlst(&p->map2, &p->map_height);
	p->y = p->map_height - p->y;
	return (EXIT_SUCCESS);
}

int		parse_sub(t_params *p, char **words, char *line)
{
	if (strcmp(words[0], "R") == 0)
		return (parse_sub_resolution(p, words));
	else if (strcmp(words[0], "NO") == 0)
		return (parse_sub_texture(p, words, NORTH));
	else if (strcmp(words[0], "SO") == 0)
		return (parse_sub_texture(p, words, SOUTH));
	else if (strcmp(words[0], "WE") == 0)
		return (parse_sub_texture(p, words, WEST));
	else if (strcmp(words[0], "EA") == 0)
		return (parse_sub_texture(p, words, EAST));
	else if (strcmp(words[0], "S") == 0)
		return (parse_sub_texture(p, words, SPRITE));
	else if (strcmp(words[0], "F") == 0)
		return (parse_sub_color(p, words, FLOOR));
	else if (strcmp(words[0], "C") == 0)
		return (parse_sub_color(p, words, CEILING));
	else
		return (parse_map(p, line));
}

int		parse(t_params *p, int fd)
{
	char	*line;
	char	**words;
	int		error;
	int		tmp;

	line = NULL;
	while ((tmp = get_next_line(fd, &line)) == 1)
	{
		if (line[0] == '\0')
			continue ;
		words = ft_split(line, ' ');
		if (words[0] != NULL)
			error = parse_sub(p, words, line);
		free_words(words);
		if (error != PARSED_MAP_LINE)
			try_free((void**)&line);
		if (error && (error != PARSED_MAP_LINE))
			return (error);
	}
	try_free((void**)&line);
	return (check_and_store_map(p));
}
