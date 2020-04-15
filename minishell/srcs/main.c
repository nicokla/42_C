/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:57:32 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/26 10:06:34 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*separate_commands(char **line)
{
	t_list	*list;
	char	**commands;
	char	**tmp;

	if (ft_strchr(*line, ';'))
	{
		list = NULL;
		commands = ft_split(*line, ';');
		tmp = commands;
		while (*commands != NULL)
		{
			ft_lstadd_back(&list, ft_lstnew(*commands));
			commands++;
		}
		free(tmp);
		free(*line);
		return (list);
	}
	else
	{
		list = ft_lstnew(ft_strdup(*line));
		free(*line);
		return (list);
	}
}

void		execute_commands(char **line)
{
	t_list		*tmp;
	t_list		*commands;

	commands = separate_commands(line);
	while (commands)
	{
		dispatch_cmd((char *)commands->content);
		tmp = commands;
		commands = commands->next;
		free(tmp->content);
		free(tmp);
	}
	*get_executed() = 0;
	*get_line() = NULL;
}

void		prompt(void)
{
	char		**line;
	char		*tmp;
	int			ret;

	line = get_line();
	*get_executed() = 0;
	*line = NULL;
	while (1)
	{
		if (!*line)
			ft_putstr("[minishell] $ ");
		ret = get_next_line(0, &tmp);
		str_append(line, tmp);
		free(tmp);
		if (ret == 0 && ft_strlen(*line))
			continue ;
		if (ret == -1 || ret == 0)
			exit(EXIT_FAILURE);
		if (check_empty(line))
			continue ;
		*get_executed() = 1;
		execute_commands(line);
	}
}

void		handle_sig(int sig)
{
	if (sig == SIGINT)
	{
		if (*get_executed() == 1)
			ft_putstr("\n");
		else
			ft_putstr("\n[minishell] $ ");
	}
	else if (sig == SIGQUIT)
	{
		if (*get_executed() == 1)
			ft_putstr("Quit (core dumped)\n");
	}
}

int			main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	signal(SIGINT, handle_sig);
	signal(SIGQUIT, handle_sig);
	create_env_list(envp);
	create_env_array();
	ft_create_stack();
	prompt();
}
