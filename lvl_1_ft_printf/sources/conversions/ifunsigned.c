/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifunsigned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:35:53 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/18 05:57:55 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*unsigned_precision_with_error(char *string, s_list *slist)
{
	char *temp;

	if(!(temp = malloc(sizeof(char) * 2)))
		return (NULL);
	temp[0] = '\0';
	return(temp);
}

char	*unsigned_precision(char *string, s_list *slist)
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

void	ifunsigned(p_list *plist, s_list *slist, va_list *args)
{
	char *send;
	char *temp;
	long value;
	int send_length;

	value = (unsigned int)va_arg(*args, unsigned int);

	temp = ft_itoa_unsigned(value);
	send = ft_strdup(temp);

	if (send[0] == '-')
		send_length = ft_strlen(send) - 1;
	else
		send_length = ft_strlen(send);
	if (slist->precision >= 0 && slist->precision > send_length && slist->precision_error == 0)
		send = unsigned_precision(send, slist);
	else if (slist->precision_error == 1)
		send = unsigned_precision_with_error(send, slist);
	unsigned_write(plist, send, slist);
	plist->format_count++;
}
