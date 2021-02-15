/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iffloat3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 21:55:02 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/14 16:04:49 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*finalize_decimal_with_precision(char *decimal_string,
											t_slist *slist)
{
	char	*final;
	int		i;
	int		f;
	int		len_decimal;

	i = 0;
	f = 0;
	len_decimal = ft_strlen(decimal_string);
	final = malloc(sizeof(char) * (len_decimal + slist->precision + 1));
	if (final == NULL)
		return (NULL);
	if (len_decimal > slist->precision)
		i = len_decimal - slist->precision;
	while (len_decimal < slist->precision)
	{
		final[f++] = '0';
		len_decimal++;
		i = 0;
	}
	while (decimal_string[i] != '\0' && i <= slist->precision)
		final[f++] = decimal_string[i++];
	final[f] = '\0';
	free(decimal_string);
	return (final);
}

char	*finalize_decimal_no_precision(char *decimal_string)
{
	char	*final;
	int		i;
	int		f;
	int		len_decimal;

	i = 0;
	f = 0;
	len_decimal = ft_strlen(decimal_string);
	final = malloc(sizeof(char) * (len_decimal + 7));
	if (final == NULL)
		return (NULL);
	if (len_decimal > 6)
		i = len_decimal - 6;
	while (len_decimal < 6)
	{
		final[f++] = '0';
		len_decimal++;
		i = 0;
	}
	while (decimal_string[i] != '\0' && i <= 6)
		final[f++] = decimal_string[i++];
	final[f] = '\0';
	free(decimal_string);
	return (final);
}

char	*finalize_integer(char *integer_string, double n, t_slist *slist)
{
	char	*final;
	int		i;
	int		f;
	int		len_integer;

	i = 0;
	f = 0;
	len_integer = ft_strlen(integer_string);
	final = malloc(sizeof(char) * (len_integer + 3));
	if (final == NULL)
		return (NULL);
	if (1 / n <= 0 && (int)n == 0 && integer_string[0] != '-')
		final[f++] = '-';
	while (integer_string[i] != '\0')
		final[f++] = integer_string[i++];
	if (slist->precision != 0)
		final[f++] = '.';
	else if (slist->precision == 0 && slist->hash == 1)
		final[f++] = '.';
	final[f] = '\0';
	free(integer_string);
	return (final);
}
