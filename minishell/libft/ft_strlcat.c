/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:36:53 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/09 09:37:00 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;

	dstlen = 0;
	while (dst[dstlen] && dstlen < size)
		dstlen++;
	i = dstlen;
	while (src[dstlen - i] && dstlen + 1 < size)
	{
		dst[dstlen] = src[dstlen - i];
		dstlen += 1;
	}
	if (i < size)
		dst[dstlen] = '\0';
	return (i + ft_strlen(src));
}
