/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:07:37 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/13 18:13:15 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	conversion_path_u(t_plist *plist,
									va_list *args, t_slist *slist)
{
	char	*format;
	int		i;

	i = plist->format_count;
	format = plist->format;
	if (format[i] == 'u')
	{
		if (slist->l == 1)
			ifunsignedl(plist, slist, args);
		else if (slist->l == 2)
			ifunsignedll(plist, slist, args);
		else if (slist->h == 1)
			ifunsignedh(plist, slist, args);
		else if (slist->h == 2)
			ifunsignedhh(plist, slist, args);
		else
			ifunsigned(plist, slist, args);
	}
}

static void	conversion_path_i(t_plist *plist,
									va_list *args, t_slist *slist)
{
	char	*format;
	int		i;

	i = plist->format_count;
	format = plist->format;
	if (format[i] == 'i')
	{
		if (slist->l == 1)
			ifintegerl(plist, slist, args);
		else if (slist->l == 2)
			ifintegerll(plist, slist, args);
		else if (slist->h == 1)
			ifintegerh(plist, slist, args);
		else if (slist->h == 2)
			ifintegerhh(plist, slist, args);
		else
			ifinteger(plist, slist, args);
	}
}

static void	conversion_path_d(t_plist *plist,
									va_list *args, t_slist *slist)
{
	char	*format;
	int		i;

	i = plist->format_count;
	format = plist->format;
	if (format[i] == 'd')
	{
		if (slist->l == 1)
			ifdigitl(plist, slist, args);
		else if (slist->l == 2)
			ifdigitll(plist, slist, args);
		else if (slist->h == 1)
			ifdigith(plist, slist, args);
		else if (slist->h == 2)
			ifdigithh(plist, slist, args);
		else
			ifdigit(plist, slist, args);
	}
}

static void	conversion2(t_plist *plist, va_list *args, t_slist *slist)
{
	int		i;
	char	*format;

	i = plist->format_count;
	format = plist->format;
	if (format[i] == 'X')
		conversion_path_x_upper(plist, args, slist);
	else if (format[i] == 'n')
		conversion_path_n(plist, args, slist);
	else if (format[i] == 'f')
		iffloat(plist, slist, args);
}

void	conversion(t_plist *plist, va_list *args, t_slist *slist)
{
	int		i;
	char	*format;

	i = plist->format_count;
	format = plist->format;
	if (format[i] == '%')
		ifpercent(plist, slist);
	else if (format[i] == 'c')
		conversion_path_c(plist, args, slist);
	else if (format[i] == 's')
		conversion_path_s(plist, args, slist);
	else if (format[i] == 'p')
		ifpointer(plist, slist, args);
	else if (format[i] == 'd')
		conversion_path_d(plist, args, slist);
	else if (format[i] == 'i')
		conversion_path_i(plist, args, slist);
	else if (format[i] == 'u')
		conversion_path_u(plist, args, slist);
	else if (format[i] == 'x')
		conversion_path_x_lower(plist, args, slist);
	else if (format[i] == 'X' || format[i] == 'n' || format[i] == 'f')
		conversion2(plist, args, slist);
}
