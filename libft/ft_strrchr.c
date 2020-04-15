/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:14:15 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/14 18:18:43 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c_int)
{
	const char	*temp;
	char		c;

	c = (char)c_int;
	temp = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			temp = s;
		s++;
	}
	if (c == '\0')
		temp = s;
	return ((char*)temp);
}
