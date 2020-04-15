/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:25:37 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/14 21:39:42 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void *answer;

	if (num == 0 || size == 0)
		return (NULL);
	answer = malloc(num * size);
	if (answer != NULL)
		ft_memset(answer, 0, num * size);
	return (answer);
}
