/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   haswidth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:27:13 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/20 04:43:44 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	haswidth(p_list *plist, s_list *slist, va_list *args) // Falta adicionar
{													// a estrela *
	int i;
	char *format;
	char *temp;
	char *numbers = "0123456789";
	int args_value;

	i = plist->format_count;
	format = plist->format;

	if (!(temp = malloc(sizeof(char) + 2)))
		return ;
	temp[0] = 0;
	temp[1] = '\0';

	if (format[i] != '\0' && ft_strchr(WIDTH, format[i]))
	{
		while(format[i] != '\0' && ft_strchr(numbers, format[i]))
		{
			temp = ft_strjoinchr(temp, format[i]);
			i++;
		}
		slist->width = ft_atoi(temp);
		plist->format_count = i;
	}
	else if (format[i] != '\0' && ft_strchr(STAR, format[i]))
	{
		args_value = va_arg(*args, int);
		if ((format[i - 1] != '\0' && format[i - 1] == '-') ||
			(format[i - 1] != '\0' && args_value < 0))
			{
				if (args_value < 0)
					args_value *= -1;
				slist->minus = args_value;
			}
		else
			slist->width = args_value;
		plist->format_count++;
	}
}
