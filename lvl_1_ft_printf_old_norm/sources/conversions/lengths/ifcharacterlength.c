/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifcharacterlength.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:12:26 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/13 19:29:44 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	ifcharacterl(t_plist *plist, t_slist *slist, va_list *args)
{
	wchar_t	send;
	int		error;

	error = 0;
	send = (unsigned int)va_arg(*args, wchar_t);
	if ((int)send > 127 || (int)send < 0)
	{
		send = 127;
		error = 1;
	}
	if (slist->lcerror != 1)
	{
		char_process(plist, send, slist);
	}
	if (error == 1)
	{
		slist->lcerror = 1;
		plist->final_format_lenght = -1;
	}
	plist->format_count++;
}
