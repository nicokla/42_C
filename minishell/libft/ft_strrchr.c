/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:36:53 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/10 16:25:39 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *ret;
	const char *temp;

	c = (unsigned char)c;
	if (c == '\0')
		return (ft_strchr(s, '\0'));
	ret = NULL;
	while ((temp = ft_strchr(s, c)) != NULL)
	{
		ret = temp;
		s = temp + 1;
	}
	return ((char *)ret);
}
