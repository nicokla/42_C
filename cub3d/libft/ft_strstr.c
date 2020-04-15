/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 00:05:17 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/11 15:18:29 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	if (*to_find == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j]
			&& str[i + j] != '\0'
			&& to_find[j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return ((char*)(&str[i]));
		i++;
	}
	return ((char*)0);
}
