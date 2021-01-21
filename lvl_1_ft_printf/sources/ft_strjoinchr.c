/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:05:12 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/16 07:05:29 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strjoinchr(const char *s1, char s2)
{
	int i;
	char *temp;
	int len;

	i = 0;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	if (!(temp = malloc((len + 2) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = s2;
	i++;
	temp[i] = '\0';
	return (temp);
}
