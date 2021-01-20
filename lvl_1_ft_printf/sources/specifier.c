/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:22:17 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/19 17:36:25 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	specifier(p_list *plist, va_list *args, s_list *slist)
{
	hasflags(plist, slist);
	haswidth(plist, slist, args);
	hasprecision(plist, slist, args);
	//haslength();
	parse(plist, args, slist);
}
