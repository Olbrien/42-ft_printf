/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifexponent4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 03:43:04 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/16 14:50:35 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*add_e_number_minus(char *final, t_slist *slist)
{
	char	*e_number;
	char	*e_prefix;
	char	*e;

	e = ft_strdup("e");
	slist->exponent *= -1;
	e_number = ft_itoa(slist->exponent);
	e_prefix = ft_strdup("-");
	e_prefix = ft_strjoin(e_prefix, e_number);
	free(e_number);
	e = ft_strjoin(e, e_prefix);
	free(e_prefix);
	final = ft_strjoin(final, e);
	free(e);
	return (final);
}

char	*add_e_number_minus_zero(char *final, t_slist *slist)
{
	char	*e_number;
	char	*e_prefix;
	char	*e;

	e = ft_strdup("e");
	slist->exponent *= -1;
	e_number = ft_itoa(slist->exponent);
	e_prefix = ft_strdup("-0");
	e_prefix = ft_strjoin(e_prefix, e_number);
	free(e_number);
	e = ft_strjoin(e, e_prefix);
	free(e_prefix);
	final = ft_strjoin(final, e);
	free(e);
	return (final);
}

char	*add_e_number_plus(char *final, t_slist *slist)
{
	char	*e_number;
	char	*e_prefix;
	char	*e;

	e = ft_strdup("e");
	e_number = ft_itoa(slist->exponent);
	e_prefix = ft_strdup("+");
	e_prefix = ft_strjoin(e_prefix, e_number);
	free(e_number);
	e = ft_strjoin(e, e_prefix);
	free(e_prefix);
	final = ft_strjoin(final, e);
	free(e);
	return (final);
}

char	*add_e_number_plus_zero(char *final, t_slist *slist)
{
	char	*e_number;
	char	*e_prefix;
	char	*e;

	e = ft_strdup("e");
	e_number = ft_itoa(slist->exponent);
	e_prefix = ft_strdup("+0");
	e_prefix = ft_strjoin(e_prefix, e_number);
	free(e_number);
	e = ft_strjoin(e, e_prefix);
	free(e_prefix);
	final = ft_strjoin(final, e);
	free(e);
	return (final);
}

char	*add_e_number(char *final, t_slist *slist)
{
	if (slist->exponent >= 0 && slist->exponent <= 9)
	{
		final = add_e_number_plus_zero(final, slist);
		return (final);
	}
	else if (slist->exponent >= 10)
	{
		final = add_e_number_plus(final, slist);
		return (final);
	}
	else if (slist->exponent < 0 && slist->exponent >= -9)
	{
		final = add_e_number_minus_zero(final, slist);
		return (final);
	}
	else if (slist->exponent <= -10)
	{
		final = add_e_number_minus(final, slist);
		return (final);
	}
	return (final);
}
