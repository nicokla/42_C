/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append_prefix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 01:57:08 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/18 18:19:35 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_str_append_prefix(char *prefix, char **ps)
{
	char	*answer;

	answer = ft_strjoin(prefix, *ps);
	if (*ps != NULL)
		free(*ps);
	*ps = answer;
}
