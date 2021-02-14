/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifcharacter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:13:32 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/14 05:36:06 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int		char_write_minus_greater(t_plist *plist, t_slist *slist, int i)
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

static int		char_write_width_greater(t_plist *plist, t_slist *slist, int i)
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

void			char_process(t_plist *plist, char character, t_slist *slist)
{
	int	i;

	i = 0;
	if (!plist)
		return ;
	if (slist->width > 0 && slist->minus == 0)
		i = char_write_width_greater(plist, slist, i);
	write(1, &character, 1);
	if (slist->minus > 0)
		i = char_write_minus_greater(plist, slist, i);
	if (plist->final_format == NULL)
	{
		plist->final_format = malloc(sizeof(char) + 2);
		if (plist->final_format == NULL)
			return ;
		plist->final_format[0] = character;
		plist->final_format[1] = '\0';
	}
	else
		plist->final_format = ft_strjoinchr(plist->final_format, character);
	plist->final_format_lenght++;
}

void	ifcharacter(t_plist *plist, t_slist *slist, va_list *args)
{
	char	send;

	send = (char)va_arg(*args, int);
	char_process(plist, send, slist);
	plist->format_count++;
}
