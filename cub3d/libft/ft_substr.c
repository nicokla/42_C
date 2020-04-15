/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:34:36 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/14 23:40:38 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*answer;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strnew(0));
	while (s[start + i] != '\0' && i < len)
		i++;
	if (!(answer = malloc(i + 1)))
		return (NULL);
	ft_memcpy(answer, s + start, i);
	answer[i] = '\0';
	return (answer);
}
