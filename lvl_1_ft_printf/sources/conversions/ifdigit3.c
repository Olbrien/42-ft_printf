/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifdigit3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:42:59 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/11 05:30:34 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	add_zeros_unecessary_function_d(int add_zeros)
{
	add_zeros = 48;
	return (add_zeros);
}

void	free_string_digit(char *string, t_slist *slist)
{
	if (slist->free == 1)
		free(string);
}

void	digit_space(t_plist *plist, t_slist *slist, char *string, int length)
{
	if (string[0] == '+' || string[0] == '-')
	{
		slist->width = length;
		slist->minus++;
		slist->zero++;
	}
	else
		slist->width = length + 1;
	slist->minus--;
	slist->zero--;
	if (slist->minus != 0)
		digit_write_width_greater(plist, slist, 0, length);
}

char	*digit_write_zeros2(t_slist *slist, char *s, char *string)
{
	if (string[0] == '-' || string[0] == '+')
		s = ft_strjoin(s, string + 1);
	else
		s = ft_strjoin(s, string);
	s = digit_precision_with_zeros(slist, string, s);
	free(string);
	return (s);
}
