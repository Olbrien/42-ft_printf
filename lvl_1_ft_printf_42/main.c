/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:20:06 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/15 18:18:34 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

#include <stdio.h>


int	main()
{
	int do_printf;
	int do_ft_printf;

	printf("\n");
	do_printf = printf("this %e scientific notation", 1.5);
	printf("\n");
	do_ft_printf = ft_printf("this %e scientific notation", 1.5);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", 7.5);
	printf("\n");
	do_ft_printf = ft_printf("%e", 7.5);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", 0.0);
	printf("\n");
	do_ft_printf = ft_printf("%e", 0.0);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", -0.0);
	printf("\n");
	do_ft_printf = ft_printf("%e", -0.0);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", 1.0);
	printf("\n");
	do_ft_printf = ft_printf("%e", 1.0);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", -3.85);
	printf("\n");
	do_ft_printf = ft_printf("%e", -3.85);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", 573.924);
	printf("\n");
	do_ft_printf = ft_printf("%e", 573.924);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", -958.125);
	printf("\n");
	do_ft_printf = ft_printf("%e", -958.125);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", 23.00041);
	printf("\n");
	do_ft_printf = ft_printf("%e", 23.00041);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", 0.000039);
	printf("\n");
	do_ft_printf = ft_printf("%e", 0.000039);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", -7.00036);
	printf("\n");
	do_ft_printf = ft_printf("%e", -7.00036);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", -0.00032);
	printf("\n");
	do_ft_printf = ft_printf("%e", -0.00032);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", 9873.000001);
	printf("\n");
	do_ft_printf = ft_printf("%e", 9873.000001);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", 999.999999);
	printf("\n");
	do_ft_printf = ft_printf("%e", 999.999999);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", -99.999999);
	printf("\n");
	do_ft_printf = ft_printf("%e", -99.999999);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", 0.999999);
	printf("\n");
	do_ft_printf = ft_printf("%e", 0.999999);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", -0.999999);
	printf("\n");
	do_ft_printf = ft_printf("%e", -0.999999);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", 23.375094499);
	printf("\n");
	do_ft_printf = ft_printf("%e", 23.375094499);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", -985.765426499);
	printf("\n");
	do_ft_printf = ft_printf("%e", -985.765426499);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);

	printf("\n");
	do_printf = printf("%e", 3.9999999);
	printf("\n");
	do_ft_printf = ft_printf("%e", 3.9999999);
	printf("\n");
	printf("%d\n", do_printf);
	printf("%d\n", do_ft_printf);




}
