/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:33:56 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/18 15:04:03 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup2(const char *src, int n)
{
	char	*p;
	int		i;

	p = malloc(sizeof(char) * (n + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i <= n)
	{
		p[i] = src[i];
		i++;
	}
	p[n] = '\0';
	return (p);
}

int		compter_mots(const char *str, char c)
{
	int i;
	int last_char_is_normal;
	int answer;

	answer = 0;
	last_char_is_normal = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c)
			&& !last_char_is_normal)
			answer++;
		last_char_is_normal = (str[i] != c);
		i++;
	}
	return (answer);
}

int		compute_next(const char *str, char c, int pos_init, char **future_str)
{
	int		i;
	int		debut;
	char	*tmp;

	i = pos_init;
	while (str[i] == c)
		i++;
	debut = i;
	i = 0;
	while (str[debut + i] != c)
		i++;
	tmp = ft_strdup2(str + debut, i);
	(*future_str) = tmp;
	return (debut + i);
}

void	*free_all(char **answers, int i)
{
	while ((--i) >= 0)
		free(answers[i]);
	free(answers);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	int		nb_mots;
	char	**answers;
	int		i;
	int		index_chars;

	if (str == NULL)
		return (NULL);
	nb_mots = compter_mots(str, c);
	answers = malloc(sizeof(char*) * (1 + nb_mots));
	if (answers == NULL)
		return (NULL);
	i = 0;
	index_chars = 0;
	while (i < nb_mots)
	{
		index_chars = compute_next(str, c, index_chars, &(answers[i]));
		if (answers[i] == NULL)
			return (free_all(answers, i));
		i++;
	}
	answers[nb_mots] = NULL;
	return (answers);
}
