/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpercent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:11:12 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/16 19:04:44 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	percent_write(char character)
{
	write(1, &character, 1);
}

void	percent_process(p_list *plist, char character, s_list *slist)
{
	int i;

	i = 0;
	if (!plist || !character)
		return ;
	percent_write(character);
	if (plist->final_format == NULL)
	{
		if (!(plist->final_format = malloc(sizeof(char) + 2)))
			return ;
		plist->final_format[0] = character;
		plist->final_format[1] = '\0';
	}
	else
		plist->final_format = ft_strjoinchr(plist->final_format, character);
	plist->final_format_lenght++;
}

void	ifpercent(p_list *plist, s_list *slist)
{
	slist->width = 0;
	slist->minus = 0;
	percent_process(plist, '%', slist);
	plist->format_count++;
}

	//char *send;
	//int i;

	//i = 0;
	/*
	if (slist->width > 0 && slist->minus == 0)
	{
		if(!(send = malloc(sizeof(char) + slist->width + 1)))
			return ;
		while (i < slist->width - 1)
		{
			send[i] = ' ';
			i++;
		}
		send[i] = '%';
		send[i + 1] = '\0';
		slist->width = 0;
		write_add_final_format_string_and_length(plist, send);
		plist->format_count++;
		return ;
	}
	else if (slist->minus > 0)
	{
		if(!(send = malloc(sizeof(char) + slist->minus + 1)))
			return ;
		send[i] = '%';
		i++;
		while (i < slist->minus)
		{
			send[i] = ' ';
			i++;
		}
		send[i] = '\0';
		slist->minus = 0;
		write_add_final_format_string_and_length(plist, send);
		plist->format_count++;
		return ;
	}
	*/
