/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hasminus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:30:28 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/27 04:04:37 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	hasminus(t_plist *plist, t_slist *slist)
{
	int		i;
	char	*format;
	char	*temp;
	char	*numbers;

	numbers = "0123456789";
	plist->format_count++;
	i = plist->format_count;
	format = plist->format;
	if (!(temp = malloc(sizeof(char) + 2)))
		return ;
	temp[0] = 0;
	temp[1] = '\0';
	if (format[i] != '\0' && ft_strchr(numbers, format[i]))
	{
		while (format[i] != '\0' && ft_strchr(numbers, format[i]))
		{
			temp = ft_strjoinchr(temp, format[i]);
			i++;
		}
		slist->minus = ft_atoi(temp);
	}
	free(temp);
	slist->width = 0;
	plist->format_count = i - 1;
}
