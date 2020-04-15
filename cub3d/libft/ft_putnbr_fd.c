/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:33:24 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/14 22:55:35 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	get_nb_digits(long n)
{
	size_t i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int nn, int fd)
{
	char	c;
	long	n;
	char	answer[15];
	size_t	num_digits;
	size_t	num_digits_saved;

	n = (long)nn;
	c = '-';
	ft_memset(answer, 0, sizeof(answer));
	if (n < 0)
	{
		n = -n;
		write(fd, &c, 1);
	}
	num_digits = get_nb_digits(n);
	num_digits_saved = num_digits;
	answer[--num_digits] = n % 10 + '0';
	n /= 10;
	while (n > 0)
	{
		answer[--num_digits] = n % 10 + '0';
		n /= 10;
	}
	write(fd, answer, num_digits_saved);
}
