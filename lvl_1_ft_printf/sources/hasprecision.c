/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hasprecision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:26:00 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/14 18:09:19 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	hasprecision3(t_plist *plist, t_slist *slist, int i)
{
	char	*format;
	char	*numbers;
	char	*temp;

	numbers = "0123456789";
	format = plist->format;
	temp = malloc(sizeof(char) + 2);
	if (temp == NULL)
		return ;
	temp[0] = 0;
	temp[1] = '\0';
	while (format[i] != '\0' && ft_strchr(numbers, format[i]))
	{
		temp = ft_strjoinchr(temp, format[i]);
		i++;
		slist->precision = ft_atoi(temp);
	}
	if (slist->precision == 0)
		slist->precision_error = 1;
	free(temp);
	plist->format_count = i;
}

static void	hasprecision2(t_plist *plist, t_slist *slist, va_list *args)
{
	slist->star_precision = va_arg(*args, unsigned int);
	slist->has_star_precision = 1;
	plist->format_count++;
}

void	hasprecision(t_plist *plist, t_slist *slist, va_list *args)
{
	int		i;
	char	*format;

	i = plist->format_count;
	format = plist->format;
	if (format[i] != '\0' && ft_strchr(PRECISION, format[i]))
	{
		i++;
		plist->format_count++;
		slist->precision = 0;
		if (format[i] != '\0' && format[i] == '*')
		{
			if ((ft_strchr(NUMBERS, format[i - 2] == 0)
					&& format[i + 1] == 'f'))
				slist->precision_error = 1;
			hasprecision2(plist, slist, args);
		}
		else
			hasprecision3(plist, slist, i);
	}
}
