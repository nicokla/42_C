/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:44:11 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 12:44:12 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_pow_long(long n, long power)
{
	if (power == 0)
		return (1);
	else if (power == 1)
		return (n);
	return (n * ft_pow_long(n, power - 1));
}
