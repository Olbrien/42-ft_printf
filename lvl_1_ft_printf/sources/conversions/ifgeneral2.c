/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifgeneral2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 03:03:34 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/11 06:03:53 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char			*finalize_g_process(char *integer_string,
							char *decimal_string, t_slist *slist, double n)
{
	char	*final;

	if (decimal_string[0] == '\0')
	{
		if (1 / n <= 0 && (int)n == 0 && integer_string[0] != '-')
		{
			free(integer_string);
			free(decimal_string);
			integer_string = ft_strdup("-0");
			return(integer_string);
		}
		final = integer_string;
		free (decimal_string);
		return(final);
	}
	integer_string = finalize_integer_g(integer_string, n, slist);
	if (slist->precision < 0)
		decimal_string = finalize_decimal_g_no_precision(decimal_string);
	else
		decimal_string = finalize_decimal_g_with_precision(decimal_string, slist);
	if (slist->hash == 1 && slist->precision == 0)
		final = integer_string;
	else
		final = ft_strjoin(integer_string, decimal_string);
	free(decimal_string);
	return (final);
}

long long		of_power_g(int ten, int after_point)
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

int				check_bankers_g_round(double n, t_slist *slist)
{
	double		temp;
	long long	integer;

	temp = n;
	integer = (long long)n;
	temp = temp - integer;
	if (slist->precision == 0)
		temp = temp * of_power_g(10, slist->precision + 1);
	else
		temp = temp * of_power_g(10, slist->precision);
	if (temp < 0)
		temp *= -1;
	if (integer % 2 == 0 && temp == 5)
	{
		return (0);
	}
	return (1);
}

double			check_precision_g_condition(double n, t_slist *slist)
{
	long double temp;

	temp = n;
	if (check_bankers_g_round(n, slist) == 0)
		return (n);
	temp = temp * of_power_g(10, slist->precision);
	if (n >= 0)
		temp += 0.5;
	else
		temp -= 0.5;
	temp = temp / of_power_g(10, slist->precision);
	return (temp);
}

long long		get_decimal_g_number_unsigned(double n, t_slist *slist,
											unsigned long long integer)
{
	double	temp;

	temp = n;
	temp = temp - integer;
	if (slist->precision < 0)
	{
		temp = temp * of_power_g(10, 5);
		if (n >= 0)
			temp += 0.5;
		else
			temp -= 0.5;
	}
	else
	{
		temp = check_precision_g_condition(temp, slist);
		temp = temp * of_power_g(10, slist->precision);
	}
	if ((long long)temp < 0)
		return ((long long)temp * -1);
	else
		return ((long long)temp);
}
