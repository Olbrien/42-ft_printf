/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hasflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:29:23 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/17 06:59:59 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	hasflags(p_list *plist, s_list *slist)
{
	int i;
	char *format;
	char *numbers = "123456789";
	//char *all_numbers = "0123456789";

	i = plist->format_count;
	format = plist->format;
	while (format[i] != '\0' && ft_strchr(FLAGS, format[i]))
	{
		if (format[i] == '-' && ft_strchr(numbers, format[i + 1]))
		{
			hasminus(plist, slist);
			i = plist->format_count;
		}

		else if (format[i] == '-' && !ft_strchr(numbers, format[i + 1]) && slist->width != 0)
		{
			slist->minus = slist->width;
			slist->width = 0;
		}

		else if (format[i] == '+')
			slist->plus = 1;
		else if (format[i] == '0' && ft_strchr(numbers, format[i + 1]))
		{
			haszeros(plist, slist);
			i = plist->format_count;
		}
		else if (format[i] == ' ')
			slist->space = 1;
		else if (format[i] == '#')
			slist->hash = 1;
		i++;
		plist->format_count++;
	}
	if (slist->plus == 1)
		slist->space = 0;

	plist->format_count = i;
}
