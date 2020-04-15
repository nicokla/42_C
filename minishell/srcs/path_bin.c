/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:57:39 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/20 15:31:14 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_hash_table_bin(t_hash_lst **table, char **path)
{
	DIR				*dir;
	struct dirent	*dp;
	char			bin[256];
	int				i;

	i = -1;
	ft_memset(bin, 0, 256);
	while (path[++i])
	{
		if ((dir = opendir(path[i])))
		{
			while ((dp = readdir(dir)) != NULL)
			{
				ft_strcpy(bin, path[i]);
				ft_strcat(bin, "/");
				ft_strcat(bin, dp->d_name);
				if (strcmp(dp->d_name, ".") && strcmp(dp->d_name, ".."))
					ft_insert_item(table, dp->d_name, bin);
			}
			ft_memset(bin, 0, 256);
			closedir(dir);
		}
	}
}

void	ft_create_stack(void)
{
	char		*path;
	char		**split;

	ft_memset(get_hash(), 0, sizeof(t_hash_lst *) * MAX_HASH);
	path = env_get_value("PATH");
	split = ft_split(path, ':');
	ft_hash_table_bin(get_hash(), split);
	free_arr(split);
}

char	*ft_build_exec(char *name_exec)
{
	unsigned int	code;
	t_hash_lst		*tmp;

	code = ft_hash_code(ft_rm_quotes(name_exec));
	tmp = ft_search(get_hash()[code], name_exec);
	if (code > MAX_HASH || !tmp)
		return (NULL);
	return (ft_strdup(tmp->value));
}
