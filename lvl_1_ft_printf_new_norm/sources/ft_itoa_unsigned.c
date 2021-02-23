/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 05:41:20 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/23 01:30:48 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	length_unsigned(long n)
{
	long	number;
	int		i;

	number = n;
	i = 0;
	if (number == 0)
		return (2);
	if (number < 0)
	{
		number *= -1;
		i++;
	}
	while (number > 0)
	{
		number = number / 10;
		i++;
	}
	return (i + 1);
}

static char	*ifmorezero_unsigned(long n)
{
	char	*str;
	int		i;
	long	number;
	long	modulus;

	i = 0;
	number = n;
	str = malloc(length_unsigned(number) * sizeof(str));
	if (str == NULL)
		return (NULL);
	str[length_unsigned(number) - 1] = '\0';
	i = length_unsigned(number) - 2;
	while (number > 0)
	{
		modulus = number % 10;
		str[i] = modulus + '0';
		number = number / 10;
		i--;
	}
	return (str);
}

static char	*iflesszero_unsigned(long n)
{
	char	*str;
	int		i;
	long	number;
	long	modulus;

	i = 0;
	number = n;
	number *= -1;
	str = malloc(length_unsigned(number) * sizeof(str));
	if (str == NULL)
		return (NULL);
	str[0] = '-';
	str[length_unsigned(number)] = '\0';
	i = length_unsigned(number) - 1;
	while (number > 0)
	{
		modulus = number % 10;
		str[i] = modulus + '0';
		number = number / 10;
		i--;
	}
	return (str);
}

static char	*ifzero_unsigned(long n)
{
	char	*str;

	str = malloc(length_unsigned(n) * sizeof(str));
	if (str == NULL)
		return (NULL);
	str[0] = 0 + '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa_unsigned(long n)
{
	char	*str;
	long	number;

	number = n;
	str = NULL;
	if (number == 0 || number == -0)
		str = ifzero_unsigned(n);
	else if (number < 0)
		str = iflesszero_unsigned(n);
	else if (number > 0)
		str = ifmorezero_unsigned(n);
	return (str);
}
