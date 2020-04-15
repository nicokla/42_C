/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:15:43 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/17 18:16:59 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (*to_find == '\0')
		return ((char*)str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j]
			&& str[i + j] != '\0'
			&& to_find[j] != '\0'
			&& (i + j) < len)
			j++;
		if (to_find[j] == '\0')
			return ((char*)(&str[i]));
		i++;
	}
	return (NULL);
}
