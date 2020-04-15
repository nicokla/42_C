/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:35:47 by cyhuet            #+#    #+#             */
/*   Updated: 2019/11/15 20:55:50 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		put_line(char **file, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*file)[i] && (*file)[i] != '\n')
		i++;
	if ((*file)[i] == '\n')
	{
		(*line) = ft_substr(*file, 0, i);
		temp = ft_strdup(&((*file)[i + 1]));
		free(*file);
		(*file) = (temp[0] == '\0') ? NULL : ft_strdup(temp);
		free(temp);
		return (1);
	}
	else
	{
		(*line) = ft_strdup(*file);
		free(*file);
		*file = NULL;
		return (0);
	}
}

int		get_return(ssize_t bytes, char **file, char **line)
{
	if (bytes < 0)
		return (-1);
	else if (bytes == 0 && !*file)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
	{
		return (put_line(file, line));
	}
}

int		get_next_line(int fd, char **line)
{
	static char *file;
	static int	s_fd;
	ssize_t		bytes;
	char		buff[BUFFER_SIZE + 1];
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	while ((bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (file && s_fd == fd)
		{
			temp = ft_strjoin(file, buff);
			free(file);
		}
		else
			temp = ft_strdup(buff);
		file = temp;
		s_fd = fd;
		if (ft_strchr(file, '\n'))
			break ;
	}
	return (get_return(bytes, &file, line));
}
