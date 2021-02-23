/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   haswidth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:27:13 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/23 01:24:55 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	haswidth3(t_plist *plist, t_slist *slist, va_list *args, int i)
{
	char	*format;
	int		args_value;

	format = plist->format;
	slist->has_star_precision = 1;
	args_value = va_arg(*args, int);
	if ((format[i - 1] != '\0' && format[i - 1] == '-')
		|| (format[i - 1] != '\0' && args_value < 0))
	{
		if (args_value < 0)
			args_value *= -1;
		slist->minus = args_value;
	}
	else
		slist->width = args_value;
	plist->format_count++;
}

static void	haswidth2(t_plist *plist, t_slist *slist, int i)
{
	char	*format;
	char	*temp;

	temp = malloc(sizeof(char) + 2);
	if (temp == NULL)
		return ;
	temp[0] = 0;
	temp[1] = '\0';
	format = plist->format;
	while (format[i] != '\0' && ft_strchr(NUMBERS, format[i]))
	{
		temp = ft_strjoinchr(temp, format[i]);
		i++;
	}
	slist->width = ft_atoi(temp);
	free(temp);
	plist->format_count = i;
}

void	haswidth(t_plist *plist, t_slist *slist, va_list *args)
{
	int		i;
	char	*format;

	i = plist->format_count;
	format = plist->format;
	if (format[i] != '\0' && ft_strchr(WIDTH, format[i]))
		haswidth2(plist, slist, i);
	else if (format[i] != '\0' && ft_strchr(STAR, format[i]))
		haswidth3(plist, slist, args, i);
}
