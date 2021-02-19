/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifhexadecimallower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 05:45:33 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/14 16:04:58 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*convert_hexadecimallower_hash(char *string)
{
	char	*temp;

	temp = malloc(sizeof(char) * ft_strlen(string) + 2);
	if (temp == NULL)
		return (NULL);
	temp[0] = '0';
	temp[1] = 'x';
	temp[2] = '\0';
	temp = ft_strjoin(temp, string);
	free(string);
	return (temp);
}

static char	*precision_hexadecimallower(char *string, t_slist *slist)
{
	int		length_to_zeros;
	int		total_length;
	int		start;
	int		i;
	char	*temp;

	i = 0;
	start = 0;
	length_to_zeros = slist->precision - (ft_strlen(string));
	total_length = ft_strlen(string) + length_to_zeros + 1;
	temp = malloc(sizeof(char) * total_length + 1);
	if (temp == NULL)
		return (NULL);
	while (length_to_zeros > 0)
	{
		temp[i++] = '0';
		length_to_zeros--;
	}
	while (string[start] != '\0')
		temp[i++] = string[start++];
	temp[i] = '\0';
	free(string);
	return (temp);
}

char		*reverse_hexadecimallower(char *string, t_slist *slist)
{
	int		i;
	int		end;
	char	*temp;

	end = ft_strlen(string) - 1;
	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen(string) + 1));
	if (temp == NULL)
		return (NULL);
	while (end > 0)
	{
		temp[i] = string[end];
		end--;
		i++;
	}
	temp[i++] = string[end];
	temp[i] = '\0';
	free(string);
	if (slist->precision >= 0 && slist->precision > (int)ft_strlen(temp) - 2)
		temp = precision_hexadecimallower(temp, slist);
	return (temp);
}

char		*convert_return_hexadecimallower(
				unsigned long long int hexadecimal_value, char *send,
				t_slist *slist)
{
	unsigned long long int	value;
	unsigned long long int	remainder;
	int						hexa;

	value = hexadecimal_value;
	if (value < 10)
		return (return_if_one_hexalowerdigit(slist, send, value));
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
	return (send);
}

void		ifhexadecimallower(t_plist *plist, t_slist *slist,
									va_list *args)
{
	char			*send;
	long long int	hexadecimal_value;

	hexadecimal_value = va_arg(*args, long long int);
	send = malloc(sizeof(char) * 2);
	if (send == NULL)
		return ;
	send[0] = '\0';
	if (slist->has_star_precision == 1 && slist->star_precision != 0)
	{
		slist->width = 0;
		if (hexadecimal_value < 0)
			slist->zero = slist->star_precision + 1;
		else
			slist->zero = slist->star_precision;
	}
	send = convert_return_hexadecimallower(hexadecimal_value, send, slist);
	if (slist->precision == 0 && hexadecimal_value == 0
		&& slist->has_star_precision == 0)
		send[0] = '\0';
	if (slist->hash == 1 && send != NULL && hexadecimal_value != 0)
		send = convert_hexadecimallower_hash(send);
	hexadecimallower_write(plist, send, slist);
	plist->format_count++;
}
