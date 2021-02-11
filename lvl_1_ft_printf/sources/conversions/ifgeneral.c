/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifgeneral.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 02:58:08 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/11 06:02:59 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*convert_to_general(char *decimal_string)
{
	char	*finish;
	int		i;
	int		f;

	f = 0;
	i = ft_strlen(decimal_string) - 1;
	if (decimal_string[i] == '0')
	{
		finish = malloc(sizeof(char) * (i + 2));
		if (finish == NULL)
			return (NULL);
		if (decimal_string[0] == '0' && decimal_string[1] == '\0')
		{
			finish[0] = '\0';
			free(decimal_string);
			return (finish);
		}
		while (decimal_string[i] == '0' && i > 0)
			i--;
		while (f <= i)
		{
			finish[f] = decimal_string[f];
			f++;
		}
		finish[f] = '\0';
		free(decimal_string);
		return (finish);
	}
	return (decimal_string);
}

static long long	get_decimal_g_number_signed(double n,
									t_slist *slist, long long integer)
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

static long long	get_integer_g_number(double n, t_slist *slist)
{
	double	temp;

	temp = n;
	if (slist->precision < 0)
	{
		temp = temp * of_power_g(10, 5);
		if (n >= 0)
			temp += 0.5;
		else
			temp -= 0.5;
		temp = temp / of_power_g(10, 5);
	}
	else
		temp = check_precision_g_condition(n, slist);
	return ((long long)temp);
}

static char	*general_process(double n, t_slist *slist)
{
	long long				integer_number;
	char					*integer_string;
	long long				decimal_number;
	char					*decimal_string;
	char					*finalized_string;

	integer_number = get_integer_g_number(n, slist);
	if (n < 0)
	{
		integer_string = ft_itoa_longlong(integer_number);
		decimal_number = get_decimal_g_number_signed(n, slist, integer_number);
	}
	else
	{
		integer_string = ft_itoa_unsigned_longlong(integer_number);
		decimal_number = get_decimal_g_number_unsigned(n, slist,
				integer_number);
	}
	printf("-->%lld", decimal_number);
	decimal_string = ft_itoa_unsigned_longlong(decimal_number);
	decimal_string = convert_to_general(decimal_string);
	printf("-->%s", decimal_string);
	finalized_string = finalize_g_process(integer_string, decimal_string, slist, n);
	return (finalized_string);
}

static char	*general_plus(t_slist *slist, char *send)
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

void	ifgeneral(t_plist *plist, t_slist *slist, va_list *args)
{
	char		*send;
	double		value;

	value = va_arg(*args, double);
	if (slist->has_star_precision == 1 && slist->precision_error == 1)
		slist->precision = -1;
	send = general_process(value, slist);
	slist->free = 1;
	send = general_plus(slist, send);
	if (slist->has_star_precision == 1 && slist->star_precision != 0)
	{
		slist->width = 0;
		if (value < 0)
			slist->zero = slist->star_precision + 1;
		else
			slist->zero = slist->star_precision;
	}
	general_write(plist, send, slist);
	plist->format_count++;
}
