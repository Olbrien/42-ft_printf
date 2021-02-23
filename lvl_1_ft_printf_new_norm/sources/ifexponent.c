/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifexponent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 03:42:43 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/23 01:31:35 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long long	get_decimal_number_signed_e(long double n,
									t_slist *slist, long long integer)
{
	long double	temp;

	temp = n;
	temp = temp - integer;
	if (slist->precision < 0)
	{
		temp = temp * of_power_e(10, 6);
		if (n >= 0)
			temp += 0.5;
		else
			temp -= 0.5;
	}
	else
	{
		temp = check_precision_condition_e(temp, slist);
		temp = temp * of_power_e(10, slist->precision);
	}
	if ((long long)temp < 0)
		return ((long long)temp * -1);
	else
		return ((long long)temp);
}

static long long	get_integer_number_e(long double n, t_slist *slist)
{
	long double	temp;

	temp = n;
	if (slist->precision < 0)
	{
		temp = temp * of_power_e(10, 6);
		if (n >= 0)
			temp += 0.5;
		else
			temp -= 0.5;
		temp = temp / of_power_e(10, 6);
	}
	else
		temp = check_precision_condition_e(n, slist);
	return ((long long)temp);
}

static char	*exponent_process(long double n, t_slist *slist)
{
	long long				integer_number;
	char					*integer_string;
	long long				decimal_number;
	char					*decimal_string;
	char					*finalized_string;

	n = transform_to_one_integer_e(n, slist);
	integer_number = get_integer_number_e(n, slist);
	integer_number = check_int_one_digit(slist, integer_number);
	if (n < 0)
	{
		integer_string = ft_itoa_longlong(integer_number);
		decimal_number = get_decimal_number_signed_e(n, slist, integer_number);
	}
	else
	{
		integer_string = ft_itoa_unsigned_longlong(integer_number);
		decimal_number = get_decimal_number_unsigned_e(n, slist,
				integer_number);
	}
	decimal_string = ft_itoa_unsigned_longlong(decimal_number);
	finalized_string = finalize_process_e(integer_string,
			decimal_string, slist, n);
	return (finalized_string);
}

static char	*exponent_plus(t_slist *slist, char *send)
{
	char	*temp;

	if (slist->plus == 1 && send[0] != '-')
	{
		temp = ft_strdup("+");
		temp = ft_strjoin(temp, send);
		free(send);
		return (temp);
	}
	return (send);
}

void	ifexponent(t_plist *plist, t_slist *slist, va_list *args)
{
	char		*send;
	double		value;

	value = va_arg(*args, double);
	if (slist->has_star_precision == 1 && slist->precision_error == 1)
		slist->precision = slist->star_precision;
	send = exponent_process(value, slist);
	slist->free = 1;
	send = exponent_plus(slist, send);
	if (slist->has_star_precision == 1 && slist->star_precision != 0)
	{
		slist->width = 0;
		if (value < 0)
			slist->zero = slist->star_precision + 1;
		else
			slist->zero = slist->star_precision;
	}
	exponent_write(plist, send, slist);
	plist->format_count++;
}
