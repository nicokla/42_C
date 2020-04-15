/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:15:43 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/14 18:18:03 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (to_find[j] != '\0'
			&& str[i] != '\0'
			&& i < len)
	{
		if (str[i] == to_find[j])
			j++;
		else
			j = 0;
		i++;
	}
	if (to_find[j] == '\0')
		return ((char*)(str + i - j));
	return (NULL);
}
