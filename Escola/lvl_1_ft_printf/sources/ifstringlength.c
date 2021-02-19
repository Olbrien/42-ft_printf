/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifstringlength.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:19:18 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/14 16:06:03 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*w_char_return(wchar_t *w_char, t_slist *slist)
{
	char	*final;
	int		i;
	int		w;
	int		z;

	i = 0;
	w = 0;
	z = 0;
	slist->free = 1;
	while (w_char[w] != '\0')
		w++;
	if (w > 0)
	{
		final = malloc(sizeof(char) + w + 1);
		if (final == NULL)
			return (NULL);
		while (w > 0)
		{
			final[i++] = w_char[z++];
			w--;
		}
		final[i] = '\0';
		return (final);
	}
	return (ft_strdup(""));
}

void	ifstringl(t_plist *plist, t_slist *slist, va_list *args)
{
	wchar_t	*w_char;
	char	*string;

	w_char = va_arg(*args, wchar_t*);
	if (w_char == NULL)
	{
		string = ft_strdup("(null)");
		slist->free = 1;
	}
	if (w_char != NULL)
		string = w_char_return(w_char, slist);
	string = string_process(plist, slist, string);
	if (plist->final_format == NULL)
		plist->final_format = ft_strdup(string);
	else
		plist->final_format = ft_strjoin(plist->final_format, string);
	if (slist->free == 1)
		free(string);
	plist->format_count++;
}
