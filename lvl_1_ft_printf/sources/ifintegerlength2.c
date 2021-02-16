/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifintegerlength2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:18:56 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/14 16:05:35 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*integer_plus_longlong(t_slist *slist, long long value)
{
	char	*temp;
	char	*send;

	if (slist->plus == 1 && value >= 0)
	{
		send = ft_strdup("+");
		temp = ft_itoa_longlong(value);
		send = ft_strjoin(send, temp);
		free(temp);
	}
	else
	{
		temp = ft_itoa_longlong(value);
		send = ft_strdup(temp);
		free(temp);
	}
	slist->free = 1;
	return (send);
}

char	*integer_plus_long(t_slist *slist, long value)
{
	char	*temp;
	char	*send;

	if (slist->plus == 1 && value >= 0)
	{
		send = ft_strdup("+");
		temp = ft_itoa_long(value);
		send = ft_strjoin(send, temp);
		free(temp);
	}
	else
	{
		temp = ft_itoa_long(value);
		send = ft_strdup(temp);
		free(temp);
	}
	slist->free = 1;
	return (send);
}
