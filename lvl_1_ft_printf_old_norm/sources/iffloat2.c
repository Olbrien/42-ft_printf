/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iffloat2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 21:52:16 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/14 16:04:46 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*finalize_process(char *integer_string,
							char *decimal_string, t_slist *slist, double n)
{
	char	*final;

	integer_string = finalize_integer(integer_string, n, slist);
	if (slist->precision < 0)
		decimal_string = finalize_decimal_no_precision(decimal_string);
	else
		decimal_string = finalize_decimal_with_precision(decimal_string, slist);
	if (slist->hash == 1 && slist->precision == 0)
		final = integer_string;
	else
		final = ft_strjoin(integer_string, decimal_string);
	free(decimal_string);
	return (final);
}

long long	of_power(int ten, int after_point)
{
	long long	temp;

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

int			check_bankers_round(double n, t_slist *slist)
{
	double		temp;
	long long	integer;

	temp = n;
	integer = (long long)n;
	temp = temp - integer;
	if (slist->precision == 0)
		temp = temp * of_power(10, slist->precision + 1);
	else
		temp = temp * of_power(10, slist->precision);
	if (temp < 0)
		temp *= -1;
	if (integer % 2 == 0 && temp == 5)
	{
		return (0);
	}
	return (1);
}

double		check_precision_condition(double n, t_slist *slist)
{
	long double	temp;

	temp = n;
	if (check_bankers_round(n, slist) == 0)
		return (n);
	temp = temp * of_power(10, slist->precision);
	if (n >= 0)
		temp += 0.5;
	else
		temp -= 0.5;
	temp = temp / of_power(10, slist->precision);
	return (temp);
}

long long	get_decimal_number_unsigned(double n, t_slist *slist,
											unsigned long long integer)
{
	double	temp;

	temp = n;
	temp = temp - integer;
	if (slist->precision < 0)
	{
		temp = temp * of_power(10, 6);
		if (n >= 0)
			temp += 0.5;
		else
			temp -= 0.5;
	}
	else
	{
		temp = check_precision_condition(temp, slist);
		temp = temp * of_power(10, slist->precision);
	}
	if ((long long)temp < 0)
		return ((long long)temp * -1);
	else
		return ((long long)temp);
}
