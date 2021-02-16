/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:48:31 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/14 16:05:39 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ifn(t_plist *plist, t_slist *slist, va_list *args)
{
	int	*n;

	n = va_arg(*args, int*);
	if (slist->width > 0)
		slist->width = 0;
	*n = plist->final_format_lenght;
	plist->format_count++;
}
