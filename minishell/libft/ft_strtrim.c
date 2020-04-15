/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:36:53 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/09 09:37:00 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static int	ft_isin(char *set, char c)
{
	int i;

	i = 0;
	while (i < (int)ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ret;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	start = 0;
	while (s1[start] && ft_isin((char *)set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && ft_isin((char *)set, s1[end]))
		end--;
	if (start > end)
	{
		if (!(ret = malloc(sizeof(ret))))
			fatal_error(strerror(errno));
		ret[0] = '\0';
		return (ret);
	}
	return (ft_substr(s1, start, end - start + 1));
}
