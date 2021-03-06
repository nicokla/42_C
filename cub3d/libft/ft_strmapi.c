/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:34:14 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/11 17:58:29 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*answer;

	if (s == 0 || f == 0)
		return (0);
	answer = malloc(ft_strlen(s) + 1);
	if (answer == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		answer[i] = f(i, s[i]);
		i++;
	}
	answer[i] = '\0';
	return (answer);
}
