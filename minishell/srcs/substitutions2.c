/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitutions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:03:34 by nicolas           #+#    #+#             */
/*   Updated: 2019/11/27 10:40:03 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	essai_avance_dollar(t_sub *sub, char *s)
{
	sub->i++;
	if (s[sub->i] == '\0' || s[sub->i] == ' '
		|| s[sub->i] == '\'' || s[sub->i] == '\"')
	{
		print_buffer(sub, "$", 1);
		return ;
	}
	if (sub->i >= sub->len_total)
		return ;
	if (s[sub->i] == '?' && (sub->extquote != '\''))
		concat_itoa(sub);
	else
		concat_env(sub, s);
}

void	ft_str_substitution(char **s)
{
	t_sub	sub;

	sub.i = 0;
	sub.j = 0;
	sub.len_total = ft_strlen(*s);
	sub.extquote = '\0';
	ft_memset(sub.quotes, 0, 2 * sizeof(int));
	ft_memset(sub.buf, 0, sizeof(sub.buf));
	while (sub.i < sub.len_total)
	{
		if ((*s)[sub.i] == '\\')
			essai_avance_backslash(&sub, *s);
		else if ((*s)[sub.i] == '\'' || (*s)[sub.i] == '\"')
			essai_avance_quote(&sub, *s);
		else if ((*s)[sub.i] == '$')
			essai_avance_dollar(&sub, *s);
		else
			sub.buf[sub.j++] = (*s)[sub.i++];
	}
	free(*s);
	*s = ft_strdup(sub.buf);
}
