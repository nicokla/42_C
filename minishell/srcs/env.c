/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:57:00 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/20 15:44:38 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_get_value(char *key)
{
	t_hash_lst	*temp;

	temp = get_env()->l;
	while (temp)
	{
		if (ft_strcmp(key, temp->key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

void	env_set_value(char *key, char *value)
{
	t_hash_lst	*temp;

	temp = get_env()->l;
	while (temp)
	{
		if (ft_strncmp(temp->key, key, ft_strlen(temp->key)) == 0)
		{
			free(temp->value);
			temp->value = ft_strdup(value);
		}
		temp = temp->next;
	}
}

int		env_size(void)
{
	t_hash_lst	*temp;
	int			i;

	i = 0;
	temp = get_env()->l;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	create_env_list(char **envp)
{
	t_hash_lst	*tmp;
	int			eq;
	t_env		*env;

	env = get_env();
	env->l = NULL;
	while (*envp)
	{
		if (!(tmp = malloc(sizeof(t_hash_lst))))
			fatal_error(strerror(errno));
		eq = ft_get_index(*envp, '=');
		tmp->key = ft_substr(*envp, 0, eq);
		tmp->value = ft_substr(*envp, eq + 1, ft_strlen(*envp) - eq);
		tmp->next = NULL;
		lstadd_back(&env->l, tmp);
		envp++;
	}
}

void	create_env_array(void)
{
	t_hash_lst	*temp;
	int			i;
	t_env		*env;

	i = 0;
	env = get_env();
	if (!(env->a = malloc(sizeof(char *) * (env_size() + 1))))
		fatal_error(strerror(errno));
	temp = env->l;
	while (i < env_size())
	{
		env->a[i] = ft_strdup(temp->key);
		str_append(&env->a[i], "=");
		str_append(&env->a[i], temp->value);
		i++;
		temp = temp->next;
	}
	env->a[i] = NULL;
}
