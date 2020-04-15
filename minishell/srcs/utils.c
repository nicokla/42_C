/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:58:11 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/25 16:53:08 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lstadd_back(t_hash_lst **alst, t_hash_lst *new)
{
	t_hash_lst	*temp;

	if (!new || !alst)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		temp = (*alst);
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	free_arr(char **arr)
{
	int		i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

char	*ft_rm_quotes(char *cmd)
{
	int i;
	int j;

	i = 0;
	while (cmd[i])
	{
		if (is_true_quote(cmd, i, '\'') ||
			is_true_quote(cmd, i, '\"'))
		{
			j = i - 1;
			while (cmd[++j])
			{
				cmd[j] = cmd[j + 1];
			}
		}
		else
			i++;
	}
	return (cmd);
}

int		arr_len(char **arr)
{
	int	count;

	count = 0;
	if (!arr)
		return (0);
	while (*arr)
	{
		count++;
		arr++;
	}
	return (count);
}

int		check_empty(char **line)
{
	char *tmp;

	tmp = *line;
	*line = ft_strtrim(*line, " \n\t");
	free(tmp);
	if (ft_strlen(*line) == 0)
	{
		free(*line);
		*line = NULL;
		return (1);
	}
	return (0);
}
