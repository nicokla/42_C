/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:34:07 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/11 17:59:42 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*answer;
	int		n1;
	int		n2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	if (!(answer = malloc(n1 + n2 + 1)))
		return (NULL);
	ft_memcpy(answer, s1, n1);
	ft_memcpy(answer + n1, s2, n2);
	answer[n1 + n2] = '\0';
	return (answer);
}
