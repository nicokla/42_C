/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:15:04 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/14 23:29:49 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (src[i] != '\0')
	{
		if (i + 1 >= size)
		{
			if (size != 0)
				dest[i] = '\0';
			while (src[i] != '\0')
				i++;
			return (i);
		}
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
