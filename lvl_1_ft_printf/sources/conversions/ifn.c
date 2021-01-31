/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:48:31 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/31 19:00:13 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void			ifn(t_plist *plist, va_list *args)
{
	int *n;

	n = va_arg(*args, int*);
	*n = plist->final_format_lenght;
	plist->format_count++;
}
