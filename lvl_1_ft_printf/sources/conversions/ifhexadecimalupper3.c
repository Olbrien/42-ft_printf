/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifhexadecimalupper3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:23:07 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/24 22:28:53 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*hexaupper_write_zeros2(t_slist *slist, char *send, char *string)
{
	if (string[0] == '-')
		send = ft_strjoin(send, string + 1);
	else
		send = ft_strjoin(send, string);
	send = hexadecimalupper_precision_with_zeros(slist, string, send);
	return (send);
}

char	*return_if_one_hexaupperdigit(t_slist *slist, char *send,
										long long int value)
{
	char	*temp;

	temp = ft_itoa(value);
	send = ft_strjoin(send, temp);
	if (slist->precision >= 0)
		send = reverse_hexadecimalupper(send, slist);
	return (send);
}
