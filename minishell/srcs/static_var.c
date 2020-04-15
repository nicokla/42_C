/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 09:16:31 by cyhuet            #+#    #+#             */
/*   Updated: 2019/11/25 09:16:36 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env		*get_env(void)
{
	static t_env env;

	return (&env);
}

t_hash_lst	**get_hash(void)
{
	static t_hash_lst *hash[MAX_HASH];

	return (hash);
}

char		**get_line(void)
{
	static char *line;

	return (&line);
}

int			*get_executed(void)
{
	static int i;

	return (&i);
}

int			*get_exit_status(void)
{
	static int status;

	return (&status);
}
