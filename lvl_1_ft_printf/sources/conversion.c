/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:07:37 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/23 20:20:50 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conversion(t_plist *plist, va_list *args, t_slist *slist)
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
		ifdigit(plist, slist, args);
	else if (format[i] == 'i')
		ifinteger(plist, slist, args);
	else if (format[i] == 'u')
		ifunsigned(plist, slist, args);
	else if (format[i] == 'x')
		ifhexadecimallower(plist, slist, args);
	else if (format[i] == 'X')
		ifhexadecimalupper(plist, slist, args);
}
