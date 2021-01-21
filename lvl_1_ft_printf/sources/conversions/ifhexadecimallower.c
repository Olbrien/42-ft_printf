/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifhexadecimallower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 05:45:33 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/19 07:28:52 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*precision_hexadecimallower(char *string, s_list *slist)
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
	if (!(temp = malloc(sizeof(char) * total_length)))
		return (NULL);
	while (length_to_zeros > 0)
	{
		temp[i++] = '0';
		length_to_zeros--;
	}
	while (string[start] != '\0')
		temp[i++] = string[start++];
	temp[i] = '\0';
	return (temp);
}

char	*reverse_hexadecimallower(char *string, s_list *slist)
{
	char *temp;
	int i;
	int end;

	end = ft_strlen(string) - 1;
	i = 0;
	if (!(temp = malloc(sizeof(char) * (ft_strlen(string) + 1))))
		return (NULL);
	while (string[end] != '\0')
	{
		temp[i] = string[end];
		end--;
		i++;
	}
	temp[i] = '\0';
	if (slist->precision >= 0 && slist->precision > (int)ft_strlen(temp)-2)
		temp = precision_hexadecimallower(temp, slist);
	return (temp);
}

char	*convert_return_hexadecimallower(long long int hexadecimal_value, char *send, s_list *slist)
{
	long long int value = hexadecimal_value;
	long long int remainder;
	char *temp;
	int hexa;

	if (value >= 0 && value < 10)
	{
		temp = ft_itoa(value);
		send = ft_strjoin(send, temp);
		if (slist->precision >= 0)
			send = reverse_hexadecimallower(send, slist);
		return (send);
	}
	remainder = value % 16;
	while (value >= 10)
	{
		if (remainder >= 10)
		{
			hexa = remainder + 87;
			send = ft_strjoinchr(send, hexa);
		}
		else
			send = ft_strjoinchr(send, (remainder + 48));
		value = value / 16;
		remainder = value % 16;
	}
	if (value != 0)
		send = ft_strjoinchr(send, (value + 48));
	send = reverse_hexadecimallower(send, slist);
	return(send);
}

void	ifhexadecimallower(p_list *plist, s_list *slist, va_list *args)
{
	char *send;
	long long int hexadecimal_value;

	hexadecimal_value = va_arg(*args, long long int);

	if(!(send = malloc(sizeof(char) * 2)))
		return ;
	send[0] = '\0';
	send = convert_return_hexadecimallower(hexadecimal_value, send, slist);
	if (slist->precision == 0 && hexadecimal_value == 0)
		send[0] = '\0';
	hexadecimallower_write(plist, send, slist);
	plist->format_count++;
}
