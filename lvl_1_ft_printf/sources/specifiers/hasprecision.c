/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hasprecision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:26:00 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/20 04:37:51 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	hasprecision(p_list *plist, s_list *slist, va_list *args)
{
	int i;
	char *format;
	char *temp;
	char *numbers = "0123456789";

	i = plist->format_count;
	format = plist->format;

	if (!(temp = malloc(sizeof(char) + 2)))
		return ;
	temp[0] = 0;
	temp[1] = '\0';

	if (format[i] != '\0' && ft_strchr(PRECISION, format[i]))
	{
		i++;
		plist->format_count++;
		slist->precision = 0;
		while (format[i] != '\0' && ft_strchr(numbers, format[i]))
		{
			temp = ft_strjoinchr(temp, format[i]);
			i++;
			slist->precision = ft_atoi(temp);
		}
		if (slist->precision == 0)
			slist->precision_error = 1;
		plist->format_count = i;
	}
	if (format[i] != '\0' && ft_strchr(STAR, format[i]))
	{
		slist->precision = va_arg(*args, unsigned int);
		plist->format_count++;
	}
}
