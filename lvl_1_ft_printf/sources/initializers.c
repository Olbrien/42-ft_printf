/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:00:25 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/17 18:25:53 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	initialize_slist(s_list *slist)
{
	slist->minus = 0;
	slist->zero = 0;
	slist->space = 0;
	slist->hash = 0;
	slist->plus = 0;

	slist->width = 0;

	slist->precision = -1;
	slist->precision_error = 0;
	slist->star = 0;

	slist->length = 0;
}

void	initialize_plist(p_list *plist, char *format)
{
	plist->format = (char *)format;
	plist->format_count = 0;
	plist->format_length = ft_strlen(format);

	plist->final_format = NULL;
	plist->final_format_lenght = 0;
}
