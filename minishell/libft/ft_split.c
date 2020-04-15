/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:36:53 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/09 09:37:00 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static void	ft_count_words(char const *s, char c, int *count)
{
	int i;
	int quote[2];

	i = 0;
	ft_memset(quote, 0, 2 * sizeof(int));
	*count = 1;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == '\'')
			quote[0]++;
		if (s[i] == '\"')
			quote[1]++;
		if (s[i] == c && quote[0] % 2 == 0 && quote[1] % 2 == 0)
		{
			*count += 1;
			i++;
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
}

static int	ft_len_split(const char *str, char c)
{
	int i;
	int quote[2];

	i = 0;
	quote[0] = 0;
	quote[1] = 0;
	while (*str)
	{
		if (*str == c && quote[0] % 2 == 0 && quote[1] % 2 == 0)
			break ;
		if (*str == '\'')
			quote[0]++;
		if (*str == '\"')
			quote[1]++;
		i++;
		str++;
	}
	return (i);
}

static void	*free_str(char **str)
{
	char	*temp;
	int		i;

	i = 0;
	while (str[i])
	{
		temp = str[i];
		free(temp);
		temp = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (0);
}

int			get_count_words(char *str, char c)
{
	int		count_words;
	char	*tmp;

	if (!ft_strlen(str))
		return (0);
	if (c != '\"' && c != '\'')
	{
		tmp = ft_strtrim(str, &c);
		ft_count_words(tmp, c, &count_words);
		free(tmp);
	}
	else
		ft_count_words(str, c, &count_words);
	return (count_words);
}

char		**ft_split(const char *s, char c)
{
	char	**str;
	int		i;
	int		count_words;
	int		j;

	if (!s)
		return (0);
	count_words = get_count_words((char *)s, c);
	if (!(str = ((char **)malloc(sizeof(*str) * (count_words + 1)))))
		fatal_error(strerror(errno));
	j = 0;
	while (count_words-- > 0)
	{
		while (*s && *s == c)
			s++;
		i = ft_len_split(s, c);
		if (!(str[j] = ft_substr(s, 0, i)))
			return (free_str(str));
		s = s + i;
		j++;
	}
	str[j] = 0;
	return (str);
}
