/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:35:12 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/24 14:17:58 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main(){
	char c = 'a';
	char *s = "hibou";//"%-05i";
	int x = -2147483648;
	void *p = s;
	unsigned int u = 99244;


	printf("----------------\n");
	int res11 = printf(":%10.p:\n", NULL);
	int res12 = ft_printf(":%10.p:\n", NULL);

	 printf("%-30.15p\n", NULL);
	 ft_printf("%-30.15p\n", NULL);
	printf(":%10.d:\n", 12);
	 ft_printf(":%10.d:\n", 12);


	// printf("%i, %i\n\n", res11, res12);

	// printf("----------------\n");
	// int res12 = printf("%");
	// int res11 = ft_printf("%");
	// printf("%i, %i\n\n", res12, res11);

	// int res12 = printf("\n:%-*.*i:", 30, 15, x);
	// printf("\n----------------\n");
	// int res11 = ft_printf(":%-*.*i:\n", 30, 15, x);
	// printf("%i, %i\n\n", res12, res11);

	// int res21 = printf("\n:%-30.15u:", u);
	// printf("\n----------------\n");
	// int res22 = ft_printf(":%-30.15u:\n", u);
	// printf("%i, %i\n\n", res22, res21);

	// int res31 = printf("\n:%-30.15s:", s);
	// printf("\n----------------\n");
	// int res32 = ft_printf(":%-30.15s:\n", s);
	// printf("%i, %i\n\n", res32, res31);

	// int res41 = printf("\n:%-30p:", p);
	// printf("\n----------------\n");
	// int res42 = ft_printf(":%-30p:\n", p);
	// 	printf("%i, %i\n\n", res42, res41);

	// int res51 = printf("\n:%-30c:", c);
	// printf("\n----------------\n");
	// int res52 = ft_printf(":%-30c:\n", c);
	// printf("%i, %i\n\n", res52, res51);

	return (0);
}
