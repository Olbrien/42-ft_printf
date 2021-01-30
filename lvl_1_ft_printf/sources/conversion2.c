/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 07:17:53 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/30 18:03:18 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			conversion_path_x_lower(t_plist *plist,
									va_list *args, t_slist *slist)
{
	char	*format;
	int		i;

	i = plist->format_count;
	format = plist->format;
	if (format[i] == 'x')
	{
		if (slist->l == 1)
			ifhexadecimallowerl(plist, slist, args);
		else if (slist->l == 2)
			ifhexadecimallowerll(plist, slist, args);
		else if (slist->h == 1)
			ifhexadecimallowerh(plist, slist, args);
		else if (slist->h == 2)
			ifhexadecimallowerhh(plist, slist, args);
		else
			ifhexadecimallower(plist, slist, args);
	}
}

void			conversion_path_x_upper(t_plist *plist,
									va_list *args, t_slist *slist)
{
	char	*format;
	int		i;

	i = plist->format_count;
	format = plist->format;
	if (format[i] == 'X')
	{
		if (slist->l == 1)
			ifhexadecimalupperl(plist, slist, args);
		else if (slist->l == 2)
			ifhexadecimalupperll(plist, slist, args);
		else if (slist->h == 1)
			ifhexadecimalupperh(plist, slist, args);
		else if (slist->h == 2)
			ifhexadecimalupperhh(plist, slist, args);
		else
			ifhexadecimalupper(plist, slist, args);
	}
}
