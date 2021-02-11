/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   haszeros.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:32:06 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/10 06:08:22 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static int	haszeros3(t_slist *slist, va_list *args, int i)
{
	slist->zero = va_arg(*args, int);
	if (slist->zero < 0)
	{
		slist->minus = slist->zero * -1;
		slist->zero = 0;
	}
	i++;
	return (i);
}

static int	haszeros2(t_plist *plist, t_slist *slist, int i)
{
	char	*format;
	char	*numbers;
	char	*temp;

	format = plist->format;
	numbers = "0123456789";
	temp = malloc(sizeof(char) + 2);
	if (temp == NULL)
		return (0);
	temp[0] = 0;
	temp[1] = '\0';
	while (format[i] != '\0' && ft_strchr(numbers, format[i]))
	{
		temp = ft_strjoinchr(temp, format[i]);
		i++;
	}
	slist->zero = ft_atoi(temp);
	free(temp);
	return (i);
}

void	haszeros(t_plist *plist, t_slist *slist, va_list *args)
{
	int		i;
	char	*format;
	char	*numbers;

	plist->format_count++;
	i = plist->format_count;
	format = plist->format;
	numbers = "0123456789";
	if (format[i] != '\0' && ft_strchr(numbers, format[i]))
		i = haszeros2(plist, slist, i);
	if (format[i] != '\0' && format[i] == '*')
		i = haszeros3(slist, args, i);
	plist->format_count = i - 1;
}
