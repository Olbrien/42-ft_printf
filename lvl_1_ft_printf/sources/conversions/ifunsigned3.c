/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifunsigned3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:05:42 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/24 17:10:00 by tisantos         ###   ########.fr       */
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
