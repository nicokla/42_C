/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:08:36 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/14 18:15:49 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int cc, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = (const unsigned char *)src;
	const unsigned char	c = (unsigned char)cc;
	size_t				i;

	d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == c)
			return ((void *)(d + i + 1));
		i++;
	}
	return (NULL);
}
