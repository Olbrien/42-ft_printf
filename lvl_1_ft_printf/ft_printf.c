/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:43:24 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/31 05:53:45 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static int		write_char_minus_greater(t_plist *plist, t_slist *slist, int i)
{
	while (i < slist->minus - 1)
	{
		write(1, " ", 1);
		plist->final_format_lenght++;
		i++;
	}
	slist->minus = 0;
	return (i);
}

static int		write_char_width_greater(t_plist *plist, t_slist *slist, int i)
{
	while (i < slist->width - 1)
	{
		write(1, " ", 1);
		plist->final_format_lenght++;
		i++;
	}
	slist->width = 0;
	return (i);
}

static void		write_char(t_plist *plist, char character, t_slist *slist)
{
	int i;

	i = 0;
	if (!plist)
		return ;
	if (slist->width > 0 && slist->minus == 0)
		i = write_char_width_greater(plist, slist, i);
	write(1, &character, 1);
	if (slist->minus > 0)
		i = write_char_minus_greater(plist, slist, i);
	if (plist->final_format == NULL)
	{
		if (!(plist->final_format = malloc(sizeof(char) * 2)))
			return ;
		plist->final_format[0] = character;
		plist->final_format[1] = '\0';
	}
	else
		plist->final_format = ft_strjoinchr(plist->final_format, character);
	plist->final_format_lenght++;
}

void			parse(t_plist *plist, va_list *args, t_slist *slist)
{
	int		i;
	char	*format;

	format = plist->format;
	i = plist->format_count;
	if (format[i] == '\0' && format[i - 1] != '\0' && format[i - 1] == '%')
		plist->final_format_lenght = -1;
	else if (format[i] != '\0' && ft_strchr(CONVERSIONS, format[i]))
		conversion(plist, args, slist);
	else if (format[i] != '\0' && ft_strchr(SPECIFIERS, format[i]))
		specifier(plist, args, slist);
}

int				ft_printf(const char *format, ...)
{
	t_plist		plist;
	t_slist		slist;
	va_list		args;

	if (format == NULL)
		return (0);
	initialize_lists(&plist, (char *)format, &slist);
	va_start(args, format);
	while (plist.format_count < plist.format_length)
	{
		if (format[plist.format_count] == '%')
		{
			plist.format_count++;
			initialize_slist(&slist);
			parse(&plist, &args, &slist);
		}
		else if (format[plist.format_count] != '%')
		{
			write_char(&plist, plist.format[plist.format_count++], &slist);
			initialize_slist(&slist);
		}
	}
	va_end(args);
	free(plist.final_format);
	return (plist.final_format_lenght);
}
