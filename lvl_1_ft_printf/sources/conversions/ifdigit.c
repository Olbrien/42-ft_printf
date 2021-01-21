/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:19:49 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/17 18:46:44 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*digit_precision_with_error(char *string, s_list *slist)
{
	char *temp;

	if(!(temp = malloc(sizeof(char) * 2)))
		return (NULL);
	temp[0] = '\0';
	return(temp);
}

char	*digit_precision(char *string, s_list *slist)
{
	int length_to_zeros;
	int total_length;
	char *temp;
	int i;
	int start;

	i = 0;
	start = 0;
	length_to_zeros = slist->precision - (ft_strlen(string));
	total_length = ft_strlen(string) + length_to_zeros + 1;
	if (!(temp = malloc(sizeof(char) * (total_length + 2))))
		return (NULL);
	if (string[start] == '-')
	{
		start++;
		temp[i++] = '-';
		length_to_zeros++;
	}
	while (length_to_zeros-- > 0)
		temp[i++] = '0';
	while (string[start] != '\0')
		temp[i++] = string[start++];
	temp[i] = '\0';
	return (temp);
}

void	ifdigit(p_list *plist, s_list *slist, va_list *args)
{
	char *send;
	char *temp;
	int value;
	int send_length;

	value = va_arg(*args, int);

	temp = ft_itoa(value);
	send = ft_strdup(temp);

	if (send[0] == '-')
		send_length = ft_strlen(send) - 1;
	else
		send_length = ft_strlen(send);
	if (slist->precision >= 0 && slist->precision > send_length && slist->precision_error == 0)
		send = digit_precision(send, slist);
	else if (slist->precision_error == 1)
		send = digit_precision_with_error(send, slist);
	digit_write(plist, send, slist);
	plist->format_count++;
}
