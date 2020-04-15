/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:21:35 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/11 17:05:47 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup2(char *src, int n)
{
	char	*p;
	int		i;

	p = malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i <= n)
	{
		p[i] = src[i];
		i++;
	}
	p[n] = '\0';
	return (p);
}

int		is_normal(char c, char *charset)
{
	int i;

	i = 0;
	if (c == '\0')
		return (0);
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int		compter_mots(char *str, char *charset)
{
	int i;
	int last_char_is_normal;
	int answer;

	answer = 0;
	last_char_is_normal = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_normal(str[i], charset)
			&& !last_char_is_normal)
			answer++;
		last_char_is_normal =
			is_normal(str[i], charset);
		i++;
	}
	return (answer);
}

int		compute_next(char *str, char *charset, int pos_init, char **future_str)
{
	int i;
	int debut;

	i = pos_init;
	while (!is_normal(str[i], charset))
		i++;
	debut = i;
	i = 0;
	while (is_normal(str[debut + i], charset))
		i++;
	(*future_str) = ft_strdup2(str + debut, i);
	return (debut + i);
}

char	**ft_split2(char *str, char *charset)
{
	int		nb_mots;
	char	**answers;
	int		index_mots;
	int		index_chars;

	nb_mots = compter_mots(str, charset);
	answers = malloc(sizeof(*answers) * (1 + nb_mots));
	index_mots = 0;
	index_chars = 0;
	while (index_mots < nb_mots)
	{
		index_chars = compute_next(str,
									charset,
									index_chars,
									&(answers[index_mots]));
		index_mots++;
	}
	answers[nb_mots] = NULL;
	return (answers);
}
