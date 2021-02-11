/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpercent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:11:12 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/10 08:34:41 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	percent_write(char character)
{
	write(1, &character, 1);
}

static void	percent_process(t_plist *plist, char character)
{
	if (!plist || !character)
		return ;
	percent_write(character);
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
	slist->width = 0;
	slist->minus = 0;
	percent_process(plist, '%');
	plist->format_count++;
}
