/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:07:37 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/29 18:34:17 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		conversionpaths(t_plist *plist, va_list *args, t_slist *slist)
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
	else if (format[i] == 'i')
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


void		conversion(t_plist *plist, va_list *args, t_slist *slist)
{
	int		i;
	char	*format;

	i = plist->format_count;
	format = plist->format;
	if (format[i] == '%')
		ifpercent(plist, slist);
	else if (format[i] == 'c')
		ifcharacter(plist, slist, args);
	else if (format[i] == 's')
		ifstring(plist, slist, args);
	else if (format[i] == 'p')
		ifpointer(plist, slist, args);
	else if (format[i] == 'd')
		conversionpaths(plist, args, slist);
	else if (format[i] == 'i')
		conversionpaths(plist, args, slist);
	else if (format[i] == 'u')
		ifunsigned(plist, slist, args);
	else if (format[i] == 'x')
		ifhexadecimallower(plist, slist, args);
	else if (format[i] == 'X')
		ifhexadecimalupper(plist, slist, args);
}
