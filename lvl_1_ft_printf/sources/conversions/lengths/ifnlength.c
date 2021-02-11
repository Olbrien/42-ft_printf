/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifnlength.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:18:59 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/10 06:31:17 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	ifnhh(t_plist *plist, t_slist *slist, va_list *args)
{
	signed char	*n;

	n = va_arg(*args, signed char*);
	if (slist->width > 0)
		slist->width = 0;
	*n = (signed char)plist->final_format_lenght;
	plist->format_count++;
}

void	ifnh(t_plist *plist, t_slist *slist, va_list *args)
{
	short int	*n;

	n = va_arg(*args, short int*);
	if (slist->width > 0)
		slist->width = 0;
	*n = (short int)plist->final_format_lenght;
	plist->format_count++;
}

void	ifnll(t_plist *plist, t_slist *slist, va_list *args)
{
	long long int	*n;

	n = va_arg(*args, long long int*);
	if (slist->width > 0)
		slist->width = 0;
	*n = (long long int)plist->final_format_lenght;
	plist->format_count++;
}

void	ifnl(t_plist *plist, t_slist *slist, va_list *args)
{
	long int	*n;

	n = va_arg(*args, long int*);
	if (slist->width > 0)
		slist->width = 0;
	*n = (long int)plist->final_format_lenght;
	plist->format_count++;
}
