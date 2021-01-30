/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifdigitlength.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 04:27:17 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/30 16:35:26 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	ifdigithh(t_plist *plist, t_slist *slist, va_list *args)
{
	char	*send;
	char	value;
	int		send_length;

	value = (char)va_arg(*args, int);
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
	if (slist->precision >= 0 && slist->precision > send_length &&
								slist->precision_error == 0)
		send = digit_precision(send, slist);
	else if (slist->precision_error == 1)
		digit_precision_error(send, slist, value);
	digit_write(plist, send, slist);
	plist->format_count++;
}

void	ifdigith(t_plist *plist, t_slist *slist, va_list *args)
{
	char		*send;
	short int	value;
	int			send_length;

	value = (short int)va_arg(*args, int);
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
	if (slist->precision >= 0 && slist->precision > send_length &&
								slist->precision_error == 0)
		send = digit_precision(send, slist);
	else if (slist->precision_error == 1)
		digit_precision_error(send, slist, value);
	digit_write(plist, send, slist);
	plist->format_count++;
}

void	ifdigitll(t_plist *plist, t_slist *slist, va_list *args)
{
	char			*send;
	long long		value;
	int				send_length;

	value = va_arg(*args, long long);
	send = digit_plus_longlong(slist, value);
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
	if (slist->precision >= 0 && slist->precision > send_length &&
								slist->precision_error == 0)
		send = digit_precision(send, slist);
	else if (slist->precision_error == 1)
		digit_precision_error(send, slist, value);
	digit_write(plist, send, slist);
	plist->format_count++;
}

void	ifdigitl(t_plist *plist, t_slist *slist, va_list *args)
{
	char		*send;
	long		value;
	int			send_length;

	value = va_arg(*args, long);
	send = digit_plus_long(slist, value);
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
	if (slist->precision >= 0 && slist->precision > send_length &&
								slist->precision_error == 0)
		send = digit_precision(send, slist);
	else if (slist->precision_error == 1)
		digit_precision_error(send, slist, value);
	digit_write(plist, send, slist);
	plist->format_count++;
}
