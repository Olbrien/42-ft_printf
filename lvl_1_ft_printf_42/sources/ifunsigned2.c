/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifunsigned2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:39:12 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/14 16:06:08 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*unsigned_precision_with_zeros(t_slist *slist,
												char *string, char *send)
{
	int		i;
	int		to_cut_len;
	char	*temp;

	to_cut_len = slist->zero - ft_strlen(string);
	i = 0;
	if (slist->zero > 0 && to_cut_len > 0 && slist->precision > 0)
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
		return (temp);
	}
	return (send);
}

static char	*unsigned_write_zeros(t_slist *slist, char *string)
{
	int		i;
	int		add_zeros;
	char	*send;

	add_zeros = slist->zero - ft_strlen(string);
	i = 0;
	if (add_zeros > 0)
	{
		send = malloc(sizeof(char) * (ft_strlen(string) + add_zeros + 2));
		if (send == NULL)
			return (NULL);
		if (string[i] == '-')
			send[i++] = '-';
		while (add_zeros > 0)
		{
			send[i++] = '0';
			add_zeros--;
		}
		send[i] = '\0';
		send = unsigned_write_zeros2(slist, send, string);
		free(string);
		return (send);
	}
	return (string);
}

static int	unsigned_write_minus_greater(t_plist *plist, t_slist *slist,
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

static int	unsigned_write_width_greater(t_plist *plist, t_slist *slist,
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

void		unsigned_write(t_plist *plist, char *string, t_slist *slist)
{
	int	i;
	int	length;

	i = 0;
	if (!plist || !string)
		return ;
	length = ft_strlen(string);
	if (slist->zero > length)
	{
		string = unsigned_write_zeros(slist, string);
		length = ft_strlen(string);
	}
	if (slist->width > 0 && slist->minus == 0)
		i = unsigned_write_width_greater(plist, slist, i, length);
	write(1, string, length);
	if (slist->minus > 0)
		i = unsigned_write_minus_greater(plist, slist, i, length);
	unsigned_write2(plist, string);
	plist->final_format_lenght += length;
}
