/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitutions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 10:50:19 by nicolas           #+#    #+#             */
/*   Updated: 2019/11/27 10:46:33 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_buffer(t_sub *sub, char *str, int len)
{
	ft_memcpy(sub->buf + sub->j, str, len);
	sub->j += len;
}

void	essai_avance_backslash(t_sub *sub, char *s)
{
	int		oldj;

	oldj = sub->j;
	sub->i++;
	if (sub->i >= sub->len_total)
		return ;
	if (s[sub->i] == 'n')
		sub->buf[sub->j++] = '\n';
	else if (s[sub->i] == 't')
		sub->buf[sub->j++] = '\t';
	else if (s[sub->i] == '\\')
		sub->buf[sub->j++] = '\\';
	if (s[sub->i] == '\"' || s[sub->i] == '\'')
	{
		if (sub->extquote == '\'' ||
			(sub->extquote == '\"' && s[sub->i] == '\''))
			print_buffer(sub, "\\", 1);
		sub->buf[sub->j++] = s[sub->i];
	}
	else if (s[sub->i] == '$' && sub->extquote != '\'')
		sub->buf[sub->j++] = '$';
	if (oldj == sub->j)
		sub->buf[sub->j++] = '\\';
	else
		sub->i++;
}

void	essai_avance_quote(t_sub *sub, char *s)
{
	if (s[sub->i] == '\"')
	{
		if (sub->extquote == '\'')
			print_buffer(sub, "\"", 1);
		if ((++(sub->quotes[1]) % 2 == 1) && (sub->quotes[0] % 2 == 0))
			sub->extquote = '\"';
	}
	else if (s[sub->i] == '\'')
	{
		if (sub->extquote == '\"')
			print_buffer(sub, "\'", 1);
		if ((++(sub->quotes[0]) % 2 == 1) && (sub->quotes[1] % 2 == 0))
			sub->extquote = '\'';
	}
	sub->i++;
}

void	concat_itoa(t_sub *sub)
{
	char *tmp;

	if (!(tmp = ft_itoa(*get_exit_status())))
		fatal_error(strerror(errno));
	print_buffer(sub, tmp, ft_strlen(tmp));
	free(tmp);
	sub->i++;
}

void	concat_env(t_sub *sub, char *s)
{
	int len;

	len = 0;
	while (((sub->i + len) < sub->len_total) &&
			(ft_isalpha(s[sub->i + len])
				|| s[sub->i + len] == '_'))
		len++;
	sub->needle = ft_substr(s, sub->i, len);
	if (sub->extquote == '\'')
	{
		print_buffer(sub, "$", 1);
		print_buffer(sub, sub->needle, ft_strlen(sub->needle));
	}
	else
	{
		sub->with = env_get_value(sub->needle) ?
			env_get_value(sub->needle) : "";
		print_buffer(sub, sub->with, ft_strlen(sub->with));
	}
	free(sub->needle);
	sub->i += len;
}
