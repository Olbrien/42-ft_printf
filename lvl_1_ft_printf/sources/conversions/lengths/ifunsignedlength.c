/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifunsignedlength.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 06:10:54 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/10 06:32:58 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	ifunsignedhh(t_plist *plist, t_slist *slist, va_list *args)
{
	char			*send;
	char			*temp;
	unsigned char	value;
	int				send_length;

	value = (unsigned char)va_arg(*args, unsigned int);
	temp = ft_itoa_unsigned(value);
	send = ft_strdup(temp);
	free(temp);
	if (slist->has_star_precision == 1 && slist->star_precision != 0)
		unsigned_star(slist, value);
	if (send[0] == '-')
		send_length = ft_strlen(send) - 1;
	else
		send_length = ft_strlen(send);
	if (slist->precision >= 0 && slist->precision > send_length
		&& slist->precision_error == 0)
		send = unsigned_precision(send, slist);
	else if (slist->precision_error == 1)
		send[0] = '\0';
	unsigned_write(plist, send, slist);
	plist->format_count++;
}

void	ifunsignedh(t_plist *plist, t_slist *slist, va_list *args)
{
	char				*send;
	char				*temp;
	short unsigned int	value;
	int					send_length;

	value = (unsigned int)va_arg(*args, unsigned int);
	temp = ft_itoa_unsigned(value);
	send = ft_strdup(temp);
	free(temp);
	if (slist->has_star_precision == 1 && slist->star_precision != 0)
		unsigned_star(slist, value);
	if (send[0] == '-')
		send_length = ft_strlen(send) - 1;
	else
		send_length = ft_strlen(send);
	if (slist->precision >= 0 && slist->precision > send_length
		&& slist->precision_error == 0)
		send = unsigned_precision(send, slist);
	else if (slist->precision_error == 1)
		send[0] = '\0';
	unsigned_write(plist, send, slist);
	plist->format_count++;
}

void	ifunsignedll(t_plist *plist, t_slist *slist, va_list *args)
{
	char						*send;
	char						*temp;
	unsigned long long int		value;
	int							send_length;

	value = (unsigned long long)va_arg(*args, unsigned long long);
	temp = ft_itoa_unsigned_longlong(value);
	send = ft_strdup(temp);
	free(temp);
	if (slist->has_star_precision == 1 && slist->star_precision != 0)
		unsigned_star(slist, value);
	if (send[0] == '-')
		send_length = ft_strlen(send) - 1;
	else
		send_length = ft_strlen(send);
	if (slist->precision >= 0 && slist->precision > send_length
		&& slist->precision_error == 0)
		send = unsigned_precision(send, slist);
	else if (slist->precision_error == 1)
		send[0] = '\0';
	unsigned_write(plist, send, slist);
	plist->format_count++;
}

void	ifunsignedl(t_plist *plist, t_slist *slist, va_list *args)
{
	char						*send;
	char						*temp;
	unsigned long int			value;
	int							send_length;

	value = (unsigned long)va_arg(*args, unsigned long);
	temp = ft_itoa_unsigned_long(value);
	send = ft_strdup(temp);
	free(temp);
	if (slist->has_star_precision == 1 && slist->star_precision != 0)
		unsigned_star(slist, value);
	if (send[0] == '-')
		send_length = ft_strlen(send) - 1;
	else
		send_length = ft_strlen(send);
	if (slist->precision >= 0 && slist->precision > send_length
		&& slist->precision_error == 0)
		send = unsigned_precision(send, slist);
	else if (slist->precision_error == 1)
		send[0] = '\0';
	unsigned_write(plist, send, slist);
	plist->format_count++;
}
