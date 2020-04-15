/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:36:53 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/09 09:37:00 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (!s1 && !s2)
		return (0);
	else if (s1 && s2)
		len = ft_strlen(s1) + ft_strlen(s2);
	else if (s1)
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		fatal_error(strerror(errno));
	if (s1)
		str = ft_strcpy(str, s1);
	else
		str = ft_strcpy(str, s2);
	if (s1 && s2)
		str = ft_strcat(str, s2);
	return (str);
}
