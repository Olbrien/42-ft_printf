/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifinteger3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:02:26 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/14 16:05:28 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	add_zeros_unecessary_function_i(int add_zeros)
{
	add_zeros = 48;
	return (add_zeros);
}

void	free_string_integer(char *string, t_slist *slist)
{
	if (slist->free == 1)
		free(string);
}

void	integer_space(t_plist *plist, t_slist *slist, char *string, int length)
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
		integer_write_width_greater(plist, slist, 0, length);
}

char	*integer_write_zeros2(t_slist *slist, char *s, char *string)
{
	if (string[0] == '-' || string[0] == '+')
		s = ft_strjoin(s, string + 1);
	else
		s = ft_strjoin(s, string);
	s = integer_precision_with_zeros(slist, string, s);
	free(string);
	return (s);
}
