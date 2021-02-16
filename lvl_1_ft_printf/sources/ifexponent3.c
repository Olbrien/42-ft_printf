/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifexponent3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 21:55:02 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/16 14:50:44 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long int	check_int_one_digit(t_slist *slist, long long integer)
{
	char	*integer_str;
	int		integer_len;

	integer_str = ft_itoa(integer);
	if (integer < 0)
		integer_len = ft_strlen(integer_str) - 1;
	else
		integer_len = ft_strlen(integer_str);
	if (integer_len == 1)
	{
		free(integer_str);
		return (integer);
	}
	integer = integer / of_power_e(10, integer_len - 1);
	slist->exponent += integer_len - 1;
	free(integer_str);
	return (integer);
}

long double	zero_case_e(long double temp, t_slist *slist)
{
	long long int	integer;

	integer = (long long)temp;
	while (integer == 0 && temp != 0)
	{
		slist->exponent++;
		temp = temp * 10;
		integer = (long long)temp;
	}
	slist->exponent *= -1;
	return (temp);
}

long double	transform_to_one_integer_e(long double temp, t_slist *slist)
{
	long long int	integer;
	char		 	*integer_string;
	int				integer_len;

	integer = (long long)temp;
	if ((integer > 0 && integer < 10)
		|| (integer < 0 && integer > -10))
		return (temp);
	else if (integer == 0)
	{
		temp = zero_case_e(temp, slist);
		return (temp);
	}
	integer_string = ft_itoa_longlong(temp);
	if (integer_string[0] == '-')
		integer_len = ft_strlen(integer_string) - 1;
	else
		integer_len = ft_strlen(integer_string);
	temp = temp / of_power_e(10, integer_len - 1);
	slist->exponent = integer_len - 1;
	free(integer_string);
	return (temp);
}
