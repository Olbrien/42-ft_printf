/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hasflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:29:23 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/14 18:09:10 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	hasflags3(t_plist *plist, t_slist *slist,
						int count)
{
	int		i;
	char	*format;
	char	*numbers;

	i = count;
	format = plist->format;
	numbers = "123456789";
	if (format[i] == ' ' && format[i - 1] != '-')
		slist->space = 1;
	else if (format[i] == ' ' && format[i - 1] == '-'
		&& ft_strchr(numbers, format[i + 1]))
	{
		slist->space = 1;
		hasminus(plist, slist);
		i = plist->format_count;
	}
	else if (format[i] == '#')
		slist->hash = 1;
	i++;
	plist->format_count++;
	return (i);
}

static int	hasflags2(t_plist *plist, t_slist *slist,
							va_list *args, int count)
{
	int		i;
	char	*format;
	char	*numbers;

	i = count;
	format = plist->format;
	numbers = "123456789";
	if (format[i] == '+' && format[i - 1] != '-')
		slist->plus = 1;
	else if (format[i] == '+' && format[i - 1] == '-'
		&& ft_strchr(numbers, format[i + 1]))
	{
		slist->plus = 1;
		hasminus(plist, slist);
		i = plist->format_count;
	}
	else if ((format[i] == '0' && ft_strchr(numbers, format[i + 1]))
		|| (format[i] == '0' && ft_strchr(STAR, format[i + 1])))
	{
		haszeros(plist, slist, args);
		i = plist->format_count;
	}
	i = hasflags3(plist, slist, i);
	return (i);
}

void	hasflags(t_plist *plist, t_slist *slist, va_list *args)
{
	int		i;
	char	*format;
	char	*numbers;

	i = plist->format_count;
	format = plist->format;
	numbers = "0123456789";
	while (format[i] != '\0' && ft_strchr(FLAGS, format[i]))
	{
		if (format[i] == '-' && ft_strchr(numbers, format[i + 1]))
		{
			hasminus(plist, slist);
			i = plist->format_count;
		}
		else if (format[i] == '-' && !ft_strchr(numbers, format[i + 1])
			&& slist->width != 0)
		{
			slist->minus = slist->width;
			slist->width = 0;
		}
		i = hasflags2(plist, slist, args, i);
	}
	if (slist->plus == 1)
		slist->space = 0;
	plist->format_count = i;
}
