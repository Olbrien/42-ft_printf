/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifstring2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 04:43:28 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/29 07:35:27 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char			*string_precision2(t_slist *slist, char *string)
{
	if (slist->precision == 0)
	{
		slist->free = 1;
		return (ft_strdup(""));
	}
	if (slist->precision >= (int)ft_strlen(string))
	{
		if (slist->precision_error == 1)
		{
			slist->free = 1;
			return (string);
		}
		slist->free = 0;
		return (string);
	}
	return (NULL);
}

char	*string_process2(t_slist *slist, char *string)
{
	if (slist->precision >= 6)
	{
		string = ft_strdup("(null)");
		slist->precision_error = 1;
		slist->free = 1;
	}
	else if (slist->precision >= 0 && slist->precision < 6)
	{
		string = "";
		slist->precision_error = 1;
	}
	else if (slist->precision < 0)
	{
		string = ft_strdup("(null)");
		slist->free = 1;
		slist->precision_error = 1;
	}
	return (string);
}
