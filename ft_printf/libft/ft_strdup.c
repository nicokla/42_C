/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:26:34 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/11 11:47:42 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*p;
	int		i;
	int		n;

	n = ft_strlen(src);
	p = malloc(sizeof(char) * (n + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i <= n)
	{
		p[i] = src[i];
		i++;
	}
	p[n] = '\0';
	return (p);
}
