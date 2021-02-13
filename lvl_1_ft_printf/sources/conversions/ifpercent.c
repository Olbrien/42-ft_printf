/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpercent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:11:12 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/13 04:19:57 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	char_write_zeros(t_plist *plist, t_slist *slist, int i)
{
	int	a;

	a = 0;
	if (slist->minus == 0 && slist->zero > 0)
	{
		while (a < slist->zero - 1)
		{
			write(1, "0", 1);
			plist->final_format_lenght++;
			a++;
		}
	}
	return (i);
}

static int	char_write_minus_greater(t_plist *plist, t_slist *slist, int i)
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

static int	char_write_width_greater(t_plist *plist, t_slist *slist, int i)
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

static void	percent_process(t_plist *plist, t_slist *slist, char character)
{
	int	i;

	i = 0;
	if (!plist || !character)
		return ;
	i = char_write_zeros(plist, slist, i);
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

void	ifpercent(t_plist *plist, t_slist *slist)
{
	percent_process(plist, slist, '%');
	plist->format_count++;
}
