/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 04:00:04 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/02 05:46:58 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*integer_string_process(char *integer_string, double n)
{
	char	*finish;
	int		i;
	int		f;

	i = 0;
	f = 0;
	if (1 / n <= 0 && (int)n == 0)
	{
		if(!(finish = malloc(sizeof(char) * ft_strlen(integer_string) + 2)))
			return (NULL);
		if (integer_string[f] != '-')
			finish[f++] = '-';
		while (integer_string[i] != '\0')
			finish[f++] = integer_string[i++];
		finish[f] = '\0';
		free (integer_string);
		return (finish);
	}
	return (integer_string);
}

static char		*decimal_string_process(char *decimal_string)
{
	int len;
	int f;
	int i;
	char *finish;

	len = ft_strlen(decimal_string);
	i = 0;
	f = 6;
	if (len < 6)
	{
		if(!(finish = malloc(sizeof(char) * 7)))
			return (NULL);
		while (f > len)
		{
			finish[i++] = '0';
			f--;
		}
		f = 0;
		while (decimal_string[f] != '\0')
			finish[i++] = decimal_string[f++];
		finish[i] = '\0';
		free (decimal_string);
		return (finish);
	}
	return (decimal_string);
}

static char		*concatenate_double(char *integer_string, char *decimal_string)
{
	int		len;
	int		i;
	int		f;
	char	*finish;

	i = 0;
	f = 0;
	len = ft_strlen(integer_string) + ft_strlen(decimal_string) + 2;

	if(!(finish = malloc(sizeof(char) * len)))
		return (NULL);
	while (integer_string[i] != '\0')
		finish[f++] = integer_string[i++];
	finish[f++]	= '.';
	i = 0;
	while (decimal_string[i] != '\0')
		finish[f++] = decimal_string[i++];
	finish[f] = '\0';
	free (integer_string);
	free (decimal_string);
	return (finish);
}

static double	round_number(double decimal, long long *integer)
{
	long long temp;
	int i;
	long long modulus;

	temp = (long long)decimal;
	i = 0;
	if (decimal < 0)
		decimal -= 0.5;
	else
		decimal += 0.5;

	temp = (long long)decimal;
	while (i < 6)
	{
		temp = temp / 10;
		i++;
	}
	modulus = temp % 2;
	if (modulus == 1)
	{
		decimal = 0;
		*integer += 1;
	}
	else if (modulus == -1)
	{
		decimal = 0;
		*integer -= 1;
	}
	return (decimal);
}

static int		ft_pow(int ten, int after_point)
{
	long long temp;

	temp = ten;
	if (after_point == 0)
		return (1);
	while (after_point > 1)
	{
		temp *= ten;
		after_point--;
	}
	return (temp);
}

static char		*convert_decimal_string(double n)
{
	long long				integer_long_long;
	char					*integer_string;
	double					decimal_double;
	char					*decimal_string;
	char					*concatenated;

	integer_long_long = (long long)n;
	decimal_double = n - (long long)n;
	decimal_double = decimal_double * ft_pow(10, 6);
	decimal_double = round_number(decimal_double, &integer_long_long);
	if (decimal_double < 0)
		decimal_double *= -1;
	decimal_string = ft_itoa_unsigned_longlong((unsigned long long)decimal_double);
	decimal_string = decimal_string_process(decimal_string);


	if (n < 0)
		integer_string = ft_itoa_longlong(integer_long_long);
	else
		integer_string = ft_itoa_unsigned_longlong(integer_long_long);
	integer_string = integer_string_process(integer_string, n);

	concatenated = concatenate_double(integer_string, decimal_string);

	return (concatenated);

}


char			*ft_itoa_double(double n)
{
	char					*finish;

	finish = convert_decimal_string(n);
	return (finish);
}
