/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 03:51:25 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/27 05:08:38 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <float.h>

# define CONVERSIONS	"cspdiuxX%"
# define SPECIFIERS		"-+0.*lh# 123456789"
# define FLAGS			"-+0 #"
# define WIDTH			"123456789"
# define PRECISION		"."
# define LENGTH			"lh"
# define STAR			"*"
# define NUMBERS		"0123456789"


typedef struct 	s_printflist
{
	char		*format;
	int			format_length;
	int			format_count;

	char		*final_format;
	int			final_format_lenght;
}				t_plist;

typedef struct 	s_specifierslist
{
	int			minus;
	int			zero;
	int			space;
	int			hash;
	int			plus;

	int			width;

	int			precision;
	int			precision_error;

	int			star_width;
	int			has_star_width;
	int			star_precision;
	int			has_star_precision;

	int			l;
	int			h;

	int			length;

	int			free;
}				t_slist;


int		ft_printf(const char *format, ...);
void	parse(t_plist *plist, va_list *args, t_slist *slist);

char	*ft_strjoinchr(char *s1, char s2);
char	*ft_itoa_unsigned(long n);

void	initialize_slist(t_slist *slist);
void	initialize_plist(t_plist *plist, char *format);


void	conversion(t_plist *plist, va_list *args, t_slist *slist);

void	ifpercent(t_plist *plist, t_slist *slist);

void	ifcharacter(t_plist *plist, t_slist *slist, va_list *args);

void	ifstring(t_plist *plist, t_slist *slist, va_list *args);
char	*string_precision2(t_slist *slist, char *string);
char	*string_process2(t_slist *slist, char *string);

void	ifpointer(t_plist *plist, t_slist *slist, va_list *args);
void	pointer_write(t_plist *plist, char *string, t_slist *slist);

void	ifdigit(t_plist *plist, t_slist *slist, va_list *args);
void	digit_write(t_plist *plist, char *string, t_slist *slist);
int		digit_write_width_greater(t_plist *plist, t_slist *slist, int i, int length);
char	*digit_write_zeros2(t_slist *slist, char *s, char *string);
char	*digit_precision_with_zeros(t_slist *slist, char *string, char *send);
void	digit_space(t_plist *plist, t_slist *slist, char *string, int length);
void	free_string_digit(char *string, t_slist *slist);

void	ifinteger(t_plist *plist, t_slist *slist, va_list *args);
void	integer_write(t_plist *plist, char *string, t_slist *slist);
int		integer_write_width_greater(t_plist *plist, t_slist *slist, int i, int length);
char	*integer_write_zeros2(t_slist *slist, char *s, char *string);
char	*integer_precision_with_zeros(t_slist *slist, char *string, char *send);
void	integer_space(t_plist *plist, t_slist *slist, char *string, int length);
void	free_string_integer(char *string, t_slist *slist);

void	ifunsigned(t_plist *plist, t_slist *slist, va_list *args);
void	unsigned_write(t_plist *plist, char *string, t_slist *slist);
char	*unsigned_precision_with_zeros(t_slist *slist, char *string, char *send);
char	*unsigned_write_zeros2(t_slist *slist, char *s, char *string);
void	unsigned_write2(t_plist *plist, char *string);

void	ifhexadecimallower(t_plist *plist, t_slist *slist, va_list *args);
char	*reverse_hexadecimallower(char *string, t_slist *slist);
void	hexadecimallower_write(t_plist *plist, char *string, t_slist *slist);
char	*hexadecimallower_precision_with_zeros(t_slist *slist, char *string, char *send);
char	*return_if_one_hexalowerdigit(t_slist *slist, char *send, long long int value);
char	*hexalower_write_zeros2(t_slist *slist, char *send, char *string);

void	ifhexadecimalupper(t_plist *plist, t_slist *slist, va_list *args);
char	*reverse_hexadecimalupper(char *string, t_slist *slist);
void	hexadecimalupper_write(t_plist *plist, char *string, t_slist *slist);
char	*hexadecimalupper_precision_with_zeros(t_slist *slist, char *string, char *send);
char	*return_if_one_hexaupperdigit(t_slist *slist, char *send, long long int value);
char	*hexaupper_write_zeros2(t_slist *slist, char *send, char *string);


void	specifier(t_plist *plist, va_list *args, t_slist *slist);

void	hasflags(t_plist *plist, t_slist *slist, va_list *args);
void	haswidth(t_plist *plist, t_slist *slist, va_list *args);
void	hasprecision(t_plist *plist, t_slist *slist, va_list *args);
void	haslength(t_plist *plist, t_slist *slist);

void	hasminus(t_plist *plist, t_slist *slist);
void	haszeros(t_plist *plist, t_slist *slist, va_list *args);

#endif
