/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:20:23 by nklarsfe          #+#    #+#             */
/*   Updated: 2020/01/28 19:29:51 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return i;
}

void	error(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

sem_t	*ft_sem_open(char const *name, int value)
{
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

void	ft_putnbr_fd(uint64_t n, int fd)
{
	char	str[13];
	int		length;

	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + (n % 10);
		n = (n / 10);
	}
	if (length > 0)
		length--;
	while (length >= 0)
		write(fd, &str[length--], 1);
}

char	*getName(char *buf, char *s, int n)
{
	int i;

	i = 0;
	while(s[i])
	{
		buf[i] = s[i];
		i++;
	}
	while (n != 0)
	{
		buf[i++] = '0' + (n % 10);
		n = (n / 10);
	}
	buf[i] = '\0';
	return buf;
}
