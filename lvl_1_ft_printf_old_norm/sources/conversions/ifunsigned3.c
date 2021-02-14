/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifunsigned3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:05:42 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/27 05:08:15 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*unsigned_write_zeros2(t_slist *slist, char *s, char *string)
{
	if (string[0] == '-' || string[0] == '+')
		s = ft_strjoin(s, string + 1);
	else
		s = ft_strjoin(s, string);
	s = unsigned_precision_with_zeros(slist, string, s);
	return (s);
}

void	unsigned_write2(t_plist *plist, char *string)
{
	if (plist->final_format == NULL)
	{
		plist->final_format = ft_strdup(string);
		free(string);
	}
	else
	{
		plist->final_format = ft_strjoin(plist->final_format, string);
		free(string);
	}
}
