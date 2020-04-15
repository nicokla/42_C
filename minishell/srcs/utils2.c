/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:58:19 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/25 20:09:16 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *cmd)
{
	*get_exit_status() = 1;
	ft_putstr(cmd);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

int		is_true_quote(char *str, int i, char c)
{
	return (str[i] == c &&
			((i >= 2 && str[i - 1] == '\\' && str[i - 2] == '\\') ||
			(i >= 1 && str[i - 1] != '\\') ||
			i == 0));
}

int		not_even(char *str)
{
	int i;
	int s_quote;
	int d_quote;

	s_quote = 0;
	d_quote = 0;
	i = -1;
	while (str[++i])
	{
		if (is_true_quote(str, i, '\''))
			s_quote++;
		if (is_true_quote(str, i, '\"'))
			d_quote++;
	}
	if (d_quote % 2 != 0 || s_quote % 2 != 0)
		return (1);
	return (0);
}

void	str_append(char **s, char *suffix)
{
	char	*answer;

	answer = ft_strjoin(*s, suffix);
	if (s != NULL)
		free(*s);
	*s = answer;
}

void	handle_not_even(char **argv)
{
	int j;
	int i;

	i = 0;
	while (argv[i] != NULL && not_even(argv[i]))
	{
		str_append(&argv[i], " ");
		str_append(&argv[i], argv[i + 1]);
		j = i;
		while (argv[++j])
			argv[j] = argv[j + 1];
		i++;
	}
}
