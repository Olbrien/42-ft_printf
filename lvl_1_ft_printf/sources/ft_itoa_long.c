/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:15:08 by marvin            #+#    #+#             */
/*   Updated: 2021/01/29 06:23:31 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_itoa_minus(long *n, long *minus, long *temp)
{
	if (*n == -2147483647 - 1)
	{
		*n = *n + 1;
		*minus = -1;
		*temp = 1;
		*n = *n * -1;
	}
	else if (*n < 0)
	{
		*minus = -1;
		*n = *n * -1;
		*temp = 0;
	}
	else if (*n >= 0)
	{
		*minus = 1;
		*temp = 0;
	}
}

static int		ft_itoa_len(long n)
{
	long long int			len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static void		ft_itoa_write(char *finish, long len, long n, long temp)
{
	while (n > 9)
	{
		finish[len--] = (n % 10) + '0' + temp;
		n = n / 10;
		temp = 0;
	}
	finish[len] = n + '0';
}

char			*ft_itoa_long(long n)
{
	long				minus;
	long				temp;
	long				len;
	char				*finish;

	ft_itoa_minus(&n, &minus, &temp);
	len = ft_itoa_len(n);
	if (minus == -1)
	{
		if (!(finish = malloc((len + 2) * sizeof(char))))
			return (NULL);
		len++;
		finish[0] = '-';
	}
	else
	{
		if (!(finish = malloc((len + 1) * sizeof(char))))
			return (NULL);
	}
	finish[len--] = '\0';
	ft_itoa_write(finish, len, n, temp);
	return (finish);
}
