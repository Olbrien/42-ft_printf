/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:09:04 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/13 19:27:33 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	format_length_return(t_plist *plist, t_slist *slist)
{
	if (slist->lcerror == 1)
	{
		return (-1);
	}
	return (plist->final_format_lenght);
}
