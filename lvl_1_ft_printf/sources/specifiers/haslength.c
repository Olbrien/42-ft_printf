/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   haslength.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:38:02 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/24 12:07:36 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	haslength(t_plist *plist, t_slist *slist)
{
	int		i;
	char	*format;

	i = plist->format_count;
	format = plist->format;
	while (format[i] != '\0' && ft_strchr(LENGTH, format[i]))
	{
		if (format[i] == 'l')
			slist->l++;
		else if (format[i] == 'h')
			slist->h++;
		i++;
		plist->format_count++;
	}
	plist->format_count = i;
}
