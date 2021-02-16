/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:22:17 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/14 16:06:20 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	specifier(t_plist *plist, va_list *args, t_slist *slist)
{
	hasflags(plist, slist, args);
	haswidth(plist, slist, args);
	hasprecision(plist, slist, args);
	haslength(plist, slist);
	parse(plist, args, slist);
}
