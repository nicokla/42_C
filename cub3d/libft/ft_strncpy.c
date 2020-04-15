/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:19:37 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/11 14:37:29 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int i;
	int n2;

	n2 = (int)n;
	i = 0;
	while (src[i] != '\0' && i < n2)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n2)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
