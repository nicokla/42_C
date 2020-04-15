/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 02:20:47 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/14 02:48:53 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_str_insert(char *s, char *sub, size_t pos)
{
	char	*answer;

	if (pos > ft_strlen(s))
		return (s);
	answer = ft_strnew(ft_strlen(s) + ft_strlen(sub));
	ft_memcpy(answer, s, pos);
	ft_memcpy(answer + pos, sub, ft_strlen(sub));
	ft_memcpy(answer + pos + ft_strlen(sub),
				s + pos,
				ft_strlen(s) - pos);
	free(s);
	return (answer);
}
