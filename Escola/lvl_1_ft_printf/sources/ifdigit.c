/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:19:49 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/19 16:33:22 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*digit_precision(char *string, t_slist *slist)
{
	int		len_zeros;
	int		i;
	int		start;
	char	*temp;

	i = 0;
	start = 0;
	len_zeros = slist->precision - (ft_strlen(string));
	temp = malloc(sizeof(char) * (ft_strlen(string) + len_zeros + 3));
	if (temp == NULL)
		return (NULL);
	if (string[start] == '-' || string[start] == '+')
	{
		temp[i++] = string[start++];
		len_zeros++;
	}
	while (len_zeros-- > 0)
		temp[i++] = '0';
	while (string[start] != '\0')
		temp[i++] = string[start++];
	temp[i] = '\0';
	if (slist->free == 1)
		free(string);
	slist->free = 1;
	return (temp);
}

char	*digit_precision_error(char *string, t_slist *slist,
										int value)
{
	if (slist->precision_error == 1 && slist->plus == 0 && string[0] == '0')
		string[0] = '\0';
	else if (slist->precision_error == 1 && slist->plus == 1 && value == 0)
		string[1] = '\0';
	else if (slist->precision_error == 1 && slist->plus == 1 && value != 0)
	{
		slist->free = 0;
		string = digit_precision(string, slist);
		free(string);
	}
	return (string);
}

char	*digit_plus(t_slist *slist, int value)
{
	char	*temp;
	char	*send;

	if (slist->plus == 1 && value >= 0)
	{
		send = ft_strdup("+");
		temp = ft_itoa(value);
		send = ft_strjoin(send, temp);
		free(temp);
	}
	else
	{
		temp = ft_itoa(value);
		send = ft_strdup(temp);
		free(temp);
	}
	slist->free = 1;
	return (send);
}

void	ifdigit(t_plist *plist, t_slist *slist, va_list *args)
{
	char	*send;
	int		value;
	int		send_length;

	value = va_arg(*args, int);
	send = digit_plus(slist, value);
	if (slist->has_star_precision == 1 && slist->star_precision != 0)
	{
		slist->width = 0;
		if (value < 0)
			slist->zero = slist->star_precision + 1;
		else
			slist->zero = slist->star_precision;
	}
	if (send[0] == '-' || send[0] == '+')
		send_length = ft_strlen(send) - 1;
	else
		send_length = ft_strlen(send);
	if (slist->precision >= 0 && slist->precision > send_length
		&& slist->precision_error == 0)
		send = digit_precision(send, slist);
	else if (slist->precision_error == 1)
		digit_precision_error(send, slist, value);
	digit_write(plist, send, slist);
	plist->format_count++;
}
