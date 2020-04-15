/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:14:30 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/11 15:24:46 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0'
			&& s2[i] != '\0' && i < n)
		i++;
	if (i != n)
		return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
	else
		return (0);
}
