/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:43:05 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 12:43:06 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_index(char *str, char c)
{
	int i;

	i = 0;
	while (*str && *str != c)
	{
		str++;
		i++;
	}
	if (!*str)
		return (-1);
	return (i);
}