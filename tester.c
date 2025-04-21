/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:19:34 by manmaria          #+#    #+#             */
/*   Updated: 2025/04/21 17:51:26 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	printf("Left-justified: %-10d\n", 99);
	printf("Forced sign: %+d\n", 99);
	printf("Forced sign: %d\n\n", 99);
	printf("name %s, age %i, time %i%.2f\n", "Dino", 15, 0, 4.20);
	/*
	printf("Width flag %%[n]d adds spaces (n - len_nbr) to the left\n");
	printf("if (n - len_nbr) <= 0, adds no spaces\n\n");
	printf("Width:[8]%8d\n", 123);
	printf("Width:[7]%7d\n", 123);
	printf("Width:[6]%6d\n", 123);
	printf("Width:[5]%5d\n", 123);
	printf("Width:[4]%4d\n", 123);
	printf("Width:[3]%3d\n", 123);
	printf("Width:[2]%2d\n", 123);
	*//*
	printf("\nPrecision flag %%.[n]f\nfor float nbr 3.14159\n\n");
	printf("Precision:[.5] %.5f\n", 3.14159);
	printf("Precision:[.4] %.4f\n", 3.14159);
	printf("Precision:[.3] %.3f\n", 3.14159);
	printf("Precision:[.2] %.2f\n", 3.14159);
	printf("Precision:[.1] %.1f\n", 3.14159);
	printf("Precision:[.0] %.0f\n", 3.14159);
	*/
	return (0);
}
