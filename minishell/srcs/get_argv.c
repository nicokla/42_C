/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 09:16:23 by cyhuet            #+#    #+#             */
/*   Updated: 2019/11/26 10:06:30 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	case_alone(t_cmd *cmd, char **argv, int i, char c)
{
	int j;

	if (c == '<')
		cmd->in->file = ft_strdup(argv[i + 1]);
	else if (c == '>')
		cmd->out->file = ft_strdup(argv[i + 1]);
	else
		cmd->out_dbl->file = ft_strdup(argv[i + 1]);
	j = i - 1;
	free(argv[j + 1]);
	free(argv[j + 2]);
	while (argv[++j])
		argv[j] = argv[j + 2];
}

static void	case_not_alone(t_cmd *cmd, char **argv, int i, char c)
{
	int j;

	j = 0;
	if (c == '<')
		cmd->in->file = ft_substr(argv[i], j + 1, ft_strlen(argv[i]) - j);
	else
		cmd->out->file = ft_substr(argv[i], j + 1, ft_strlen(argv[i]) - j);
	j = i - 1;
	free(argv[j + 1]);
	while (argv[++j])
		argv[j] = argv[j + 1];
}

static void	get_rdir(t_cmd *cmd, char **argv, int i, char c)
{
	int		j;
	char	*tmp;

	j = ft_get_index(argv[i], c);
	if (j == 0)
	{
		if (ft_strlen(argv[i]) == 1)
			case_alone(cmd, argv, i, c);
		else
			case_not_alone(cmd, argv, i, c);
	}
	else
	{
		if (c == '<')
			cmd->in->file = ft_substr(argv[i], j + 1, ft_strlen(argv[i]) - j);
		else
			cmd->out->file = ft_substr(argv[i], j + 1, ft_strlen(argv[i]) - j);
		tmp = argv[i];
		argv[i] = ft_substr(argv[i], 0, j);
		free(tmp);
	}
}

static void	handle_append(t_cmd *cmd, char **argv, int i)
{
	int		j;
	char	*tmp;

	j = ft_get_index(argv[i], '>');
	if (j == 0)
		if (ft_strlen(argv[i]) == 2)
			case_alone(cmd, argv, i, 'a');
		else
		{
			cmd->out_dbl->file = ft_substr(argv[i], j + 2,
				ft_strlen(argv[i]) - j);
			j = i - 1;
			free(argv[j + 1]);
			while (argv[++j])
				argv[j] = argv[j + 1];
		}
	else
	{
		cmd->out_dbl->file = ft_substr(argv[i], j + 2, ft_strlen(argv[i]) - j);
		tmp = argv[i];
		argv[i] = ft_substr(argv[i], 0, j);
		free(tmp);
	}
}

void		get_argv(t_cmd *cmd)
{
	char	**argv;
	int		i;

	argv = ft_split(cmd->str, ' ');
	i = 0;
	handle_not_even(argv);
	while (argv[i])
	{
		ft_str_substitution(&argv[i]);
		if (ft_strchr(argv[i], '<'))
			get_rdir(cmd, argv, i, '<');
		else if (ft_strnstr(argv[i], ">>", ft_strlen(argv[i])) != NULL)
			handle_append(cmd, argv, i);
		else if (ft_strchr(argv[i], '>'))
			get_rdir(cmd, argv, i, '>');
		else
			i++;
	}
	cmd->argv = argv;
}
