/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:36:53 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/09 09:37:00 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		slen;

	slen = ft_strlen(s) + 1;
	if (!(str = (char *)malloc(sizeof(char) * slen)))
		fatal_error(strerror(errno));
	ft_memcpy(str, s, slen);
	return (str);
}
