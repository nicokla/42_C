/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:34:25 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/18 15:14:26 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	min;
	size_t	max;
	size_t	len;

	if (!s || !set)
		return (NULL);
	min = 0;
	while (s[min] != '\0'
			&& ft_strchr(set, s[min]))
		min++;
	max = ft_strlen(s);
	while (min < max
			&& ft_strchr(set, s[max - 1]))
		max--;
	if (min == max)
		return (ft_strnew(1));
	len = max - min;
	return (ft_substr(s, min, len));
}
