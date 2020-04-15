/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:36:53 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/09 09:37:00 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static int	ft_size_num(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int			size;
	long int	num;
	char		*str;
	int			i;

	num = n;
	size = ft_size_num(num);
	if (num < 0 || size == 0)
		size++;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		fatal_error(strerror(errno));
	i = 0;
	if (num < 0)
	{
		str[i++] = '-';
		num *= -1;
	}
	str[size--] = '\0';
	while (size >= i)
	{
		str[size] = (num % 10) + '0';
		size--;
		num /= 10;
	}
	return (str);
}
