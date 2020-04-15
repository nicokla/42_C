/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:36:53 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/09 09:37:00 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src2;
	unsigned char		*dest2;
	size_t				i;

	if (!dest && !src)
		return (0);
	i = 0;
	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	if (src2 < dest2)
		while (n-- > 0)
			*(dest2 + n) = *(src2 + n);
	else
		while (i < n)
		{
			*(dest2 + i) = *(src2 + i);
			i++;
		}
	return (dest);
}
