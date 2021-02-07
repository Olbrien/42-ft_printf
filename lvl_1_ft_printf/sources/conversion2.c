/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 07:17:53 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/07 06:16:24 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			conversion_path_f(t_plist *plist,
									va_list *args, t_slist *slist)
{
	char	*format;
	int		i;

	i = plist->format_count;
	format = plist->format;
	if (format[i] == 'f')
	{
		if (slist->l == 1)
			printf("l");//iffloatl(plist, args);
		else if (slist->l == 2)
			printf("ll");//iffloatll(plist, args);
		else if (slist->h == 1)
			printf("h");//iffloath(plist, args);
		else if (slist->h == 2)
			printf("hh");//iffloathh(plist, args);
		else
			iffloat(plist, slist, args);
	}
}

void			conversion_path_n(t_plist *plist,
									va_list *args, t_slist *slist)
{
	char	*format;
	int		i;

	i = plist->format_count;
	format = plist->format;
	if (format[i] == 'n')
	{
		if (slist->l == 1)
			ifnl(plist, slist, args);
		else if (slist->l == 2)
			ifnll(plist, slist, args);
		else if (slist->h == 1)
			ifnh(plist, slist, args);
		else if (slist->h == 2)
			ifnhh(plist, slist, args);
		else
			ifn(plist, slist, args);
	}
}

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
