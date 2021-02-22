/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifdigit2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 06:07:07 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/21 15:02:06 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*digit_precision_with_zeros(t_slist *slist, char *string,
											char *send)
{
	int		i;
	int		to_cut_len;
	char	*temp;

	to_cut_len = slist->zero - ft_strlen(string);
	i = 0;
	if ((slist->zero > 0 && to_cut_len > 0 && slist->precision > 0) ||
		(slist->zero > 0 && to_cut_len > 0 && slist->precision_error == 1))
	{
		temp = malloc(sizeof(char) * ft_strlen(string) + to_cut_len + 2);
		if (temp == NULL)
			return (NULL);
		while (to_cut_len > 0)
		{
			temp[i++] = ' ';
			to_cut_len--;
		}
		temp[i] = '\0';
		temp = ft_strjoin(temp, string);
		free(send);
		if (slist->free == 0)
			free(string);
		return (temp);
	}
	return (send);
}

static char	*digit_write_zeros(t_slist *slist, char *string)
{
	char	*s;
	int		add_zeros;
	int		i;

	i = 0;
	add_zeros = slist->zero - ft_strlen(string);
	if (add_zeros > 0)
	{
		s = malloc(sizeof(char) * (ft_strlen(string) + add_zeros + 2));
		if (s == NULL)
			return (NULL);
		if (string[i] == '-' || string[i] == '+')
			s[i++] = string[0];
		while (add_zeros > 0)
			s[i++] = add_zeros_unecessary_function_d(add_zeros--);
		s[i] = '\0';
		s = digit_write_zeros2(slist, s, string);
		if (slist->free == 0)
			free(string);
		slist->free = 1;
		return (s);
	}
	return (string);
}

static int	digit_write_minus_greater(t_plist *plist, t_slist *slist,
											int i, int length)
{
	int	count;

	count = i + length;
	if (length >= slist->minus)
	{
		slist->minus = 0;
		return (0);
	}
	else if (length < slist->minus)
	{
		while (count < slist->minus)
		{
			write(1, " ", 1);
			plist->final_format_lenght++;
			count++;
		}
	}
	slist->minus = 0;
	return (i);
}

int			digit_write_width_greater(t_plist *plist, t_slist *slist,
											int i, int length)
{
	int	count;

	count = i + length;
	if (length >= slist->width)
	{
		slist->width = 0;
		return (0);
	}
	else if (length < slist->width)
	{
		while (count < slist->width)
		{
			write(1, " ", 1);
			plist->final_format_lenght++;
			count++;
		}
	}
	slist->width = 0;
	return (i);
}

void		digit_write(t_plist *plist, char *string, t_slist *slist)
{
	int	i;
	int	length;

	i = 0;
	if (!plist || !string)
		return ;
	length = ft_strlen(string);
	if (slist->space == 1 && slist->width <= length)
		digit_space(plist, slist, string, length);
	if (slist->zero > length)
	{
		string = digit_write_zeros(slist, string);
		length = ft_strlen(string);
	}
	if (slist->width > 0 && slist->minus == 0)
		i = digit_write_width_greater(plist, slist, i, length);
	write(1, string, length);
	if (slist->minus > 0)
		i = digit_write_minus_greater(plist, slist, i, length);
	if (plist->final_format == NULL)
		plist->final_format = ft_strdup(string);
	else
		plist->final_format = ft_strjoin(plist->final_format, string);
	plist->final_format_lenght += length;
	free_string_digit(string, slist);
}
