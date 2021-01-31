/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifhexadecimallower3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:36:21 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/31 05:44:05 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int		find_char(char *send)
{
	int i;

	i = 0;
	while (send[i] != 'x' && send[i] != '\0')
		i++;
	return (i);
}

char			*hexalower_write_zeros2(t_slist *slist, char *send,
										char *string)
{
	if (string[0] == '-')
		send = ft_strjoin(send, string + 1);
	else
		send = ft_strjoin(send, string);
	if (ft_strchr(send, 'x') && ft_strlen(send) > ft_strlen(string))
	{
		send[find_char(send)] = '0';
		send[1] = 'x';
	}
	send = hexadecimallower_precision_with_zeros(slist, string, send);
	return (send);
}

char			*return_if_one_hexalowerdigit(t_slist *slist, char *send,
										long long int value)
{
	char	*temp;

	temp = ft_itoa(value);
	send = ft_strjoin(send, temp);
	if (slist->precision >= 0)
		send = reverse_hexadecimallower(send, slist);
	free(temp);
	return (send);
}
