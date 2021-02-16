/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifhexadecimalupperlength.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:45:09 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/14 16:05:19 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ifhexadecimalupperhh(t_plist *plist, t_slist *slist, va_list *args)
{
	char					*send;
	unsigned char			hexadecimal_value;

	hexadecimal_value = (unsigned char)va_arg(*args, int);
	send = malloc(sizeof(char) * 2);
	if (send == NULL)
		return ;
	send[0] = '\0';
	if (slist->has_star_precision == 1 && slist->star_precision != 0)
	{
		slist->width = 0;
		slist->zero = slist->star_precision;
	}
	send = convert_return_hexadecimalupper(hexadecimal_value, send, slist);
	if (slist->precision == 0 && hexadecimal_value == 0
		&& slist->has_star_precision == 0)
		send[0] = '\0';
	if (slist->hash == 1 && send != NULL && hexadecimal_value != 0)
		send = convert_hexadecimalupper_hash(send);
	hexadecimalupper_write(plist, send, slist);
	plist->format_count++;
}

void	ifhexadecimalupperh(t_plist *plist, t_slist *slist, va_list *args)
{
	char						*send;
	short unsigned int			hexadecimal_value;

	hexadecimal_value = (short unsigned int)va_arg(*args, unsigned int);
	send = malloc(sizeof(char) * 2);
	if (send == NULL)
		return ;
	send[0] = '\0';
	if (slist->has_star_precision == 1 && slist->star_precision != 0)
	{
		slist->width = 0;
		slist->zero = slist->star_precision;
	}
	send = convert_return_hexadecimalupper(hexadecimal_value, send, slist);
	if (slist->precision == 0 && hexadecimal_value == 0
		&& slist->has_star_precision == 0)
		send[0] = '\0';
	if (slist->hash == 1 && send != NULL && hexadecimal_value != 0)
		send = convert_hexadecimalupper_hash(send);
	hexadecimalupper_write(plist, send, slist);
	plist->format_count++;
}

void	ifhexadecimalupperll(t_plist *plist, t_slist *slist, va_list *args)
{
	char							*send;
	unsigned long long int			hexadecimal_value;

	hexadecimal_value = (unsigned long long int)va_arg(*args,
			unsigned long long int);
	send = malloc(sizeof(char) * 2);
	if (send == NULL)
		return ;
	send[0] = '\0';
	if (slist->has_star_precision == 1 && slist->star_precision != 0)
	{
		slist->width = 0;
		slist->zero = slist->star_precision;
	}
	send = convert_return_hexadecimalupper(hexadecimal_value, send, slist);
	if (slist->precision == 0 && hexadecimal_value == 0
		&& slist->has_star_precision == 0)
		send[0] = '\0';
	if (slist->hash == 1 && send != NULL && hexadecimal_value != 0)
		send = convert_hexadecimalupper_hash(send);
	hexadecimalupper_write(plist, send, slist);
	plist->format_count++;
}

void	ifhexadecimalupperl(t_plist *plist, t_slist *slist, va_list *args)
{
	char						*send;
	unsigned long int			hexadecimal_value;

	hexadecimal_value = (unsigned long int)va_arg(*args, unsigned long int);
	send = malloc(sizeof(char) * 2);
	if (send == NULL)
		return ;
	send[0] = '\0';
	if (slist->has_star_precision == 1 && slist->star_precision != 0)
	{
		slist->width = 0;
		slist->zero = slist->star_precision;
	}
	send = convert_return_hexadecimalupper(hexadecimal_value, send, slist);
	if (slist->precision == 0 && hexadecimal_value == 0
		&& slist->has_star_precision == 0)
		send[0] = '\0';
	if (slist->hash == 1 && send != NULL && hexadecimal_value != 0)
		send = convert_hexadecimalupper_hash(send);
	hexadecimalupper_write(plist, send, slist);
	plist->format_count++;
}
