/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:13:32 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/17 17:01:20 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c_int)
{
	char c;

	c = (char)c_int;
	while (*s != c && *s != '\0')
		s++;
	if (*s == '\0' && c != '\0')
		return (NULL);
	return ((char *)s);
}
