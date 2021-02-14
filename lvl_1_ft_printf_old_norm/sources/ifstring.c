/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifstring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:16:07 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/14 16:05:57 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	string_write_minus_greater(t_plist *plist, t_slist *slist,
											int i, int length)
{
	int	count;

	count = i + length;
	if (length >= slist->minus)
	{
		slist->minus = 0;
		return (0);
	}
	else if (length < slist->minus)
	{
		while (count < slist->minus)
		{
			write(1, " ", 1);
			plist->final_format_lenght++;
			count++;
		}
	}
	slist->minus = 0;
	return (i);
}

static int	string_write_width_greater(t_plist *plist, t_slist *slist,
											int i, int length)
{
	int	count;

	count = i + length;
	if (length >= slist->width)
	{
		slist->width = 0;
		return (0);
	}
	else if (length < slist->width)
	{
		while (count < slist->width)
		{
			write(1, " ", 1);
			plist->final_format_lenght++;
			count++;
		}
	}
	slist->width = 0;
	return (i);
}

static char	*string_precision(t_slist *slist, char *string)
{
	int		i;
	char	*send;
	int		remove_length;

	i = 0;
	remove_length = slist->precision;
	if (slist->precision == 0 || slist->precision >= (int)ft_strlen(string))
		return (string_precision2(slist, string));
	if (remove_length > 0)
	{
		send = malloc(sizeof(char) * (remove_length + 1));
		if (send == NULL)
			return (NULL);
		while (remove_length > 0)
		{
			send[i] = string[i];
			i++;
			remove_length--;
		}
		send[i] = '\0';
		slist->precision = -1;
		slist->free = 1;
		return (send);
	}
	return (string);
}

char		*string_process(t_plist *plist, t_slist *slist, char *string)
{
	int	i;
	int	length;

	i = 0;
	if (slist->has_star_precision == 1 && slist->star_precision != 0)
		slist->precision = slist->star_precision;
	if (string == NULL)
		string = string_process2(slist, string);
	if (slist->precision >= 0)
		string = string_precision(slist, string);
	length = ft_strlen(string);
	if (slist->width > 0 && slist->minus == 0)
		i = string_write_width_greater(plist, slist, i, length);
	write(1, string, length);
	if (slist->minus > 0)
		i = string_write_minus_greater(plist, slist, i, length);
	plist->final_format_lenght += length;
	return (string);
}

void		ifstring(t_plist *plist, t_slist *slist, va_list *args)
{
	char	*string;

	string = va_arg(*args, char*);
	string = string_process(plist, slist, string);
	if (plist->final_format == NULL)
		plist->final_format = ft_strdup(string);
	else
		plist->final_format = ft_strjoin(plist->final_format, string);
	if (slist->free == 1)
		free(string);
	plist->format_count++;
}
