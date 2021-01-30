/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 03:51:25 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/30 08:03:26 by tisantos         ###   ########.fr       */
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
char	*ft_itoa_unsigned_long(unsigned long int n);
char	*ft_itoa_unsigned_longlong(unsigned long long int n);
char	*ft_itoa_long(long n);
char	*ft_itoa_longlong(long long n);

void	initialize_slist(t_slist *slist);
void	initialize_plist(t_plist *plist, char *format);


void	conversion(t_plist *plist, va_list *args, t_slist *slist);
void	conversion_path_x(t_plist *plist, va_list *args, t_slist *slist);

void	ifpercent(t_plist *plist, t_slist *slist);

void	ifcharacter(t_plist *plist, t_slist *slist, va_list *args);

void	ifstring(t_plist *plist, t_slist *slist, va_list *args);
char	*string_precision2(t_slist *slist, char *string);
char	*string_process2(t_slist *slist, char *string);

void	ifpointer(t_plist *plist, t_slist *slist, va_list *args);
void	pointer_write(t_plist *plist, char *string, t_slist *slist);

void	ifdigit(t_plist *plist, t_slist *slist, va_list *args);
char	*digit_plus(t_slist *slist, int value);
void	digit_write(t_plist *plist, char *string, t_slist *slist);
char	*digit_precision(char *string, t_slist *slist);
char	*digit_precision_error(char *string, t_slist *slist, int value);
int		digit_write_width_greater(t_plist *plist, t_slist *slist, int i, int length);
char	*digit_write_zeros2(t_slist *slist, char *s, char *string);
char	*digit_precision_with_zeros(t_slist *slist, char *string, char *send);
void	digit_space(t_plist *plist, t_slist *slist, char *string, int length);
void	free_string_digit(char *string, t_slist *slist);

void	ifdigithh(t_plist *plist, t_slist *slist, va_list *args);
void	ifdigith(t_plist *plist, t_slist *slist, va_list *args);
void	ifdigitll(t_plist *plist, t_slist *slist, va_list *args);
void	ifdigitl(t_plist *plist, t_slist *slist, va_list *args);
char	*digit_plus_long(t_slist *slist, long value);
char	*digit_plus_longlong(t_slist *slist, long long value);

void	ifinteger(t_plist *plist, t_slist *slist, va_list *args);
char	*integer_plus(t_slist *slist, int value);
void	integer_write(t_plist *plist, char *string, t_slist *slist);
char	*integer_precision(char *string, t_slist *slist);
char	*integer_precision_error(char *string, t_slist *slist, int value);
int		integer_write_width_greater(t_plist *plist, t_slist *slist, int i, int length);
char	*integer_write_zeros2(t_slist *slist, char *s, char *string);
char	*integer_precision_with_zeros(t_slist *slist, char *string, char *send);
void	integer_space(t_plist *plist, t_slist *slist, char *string, int length);
void	free_string_integer(char *string, t_slist *slist);

void	ifintegerhh(t_plist *plist, t_slist *slist, va_list *args);
void	ifintegerh(t_plist *plist, t_slist *slist, va_list *args);
void	ifintegerll(t_plist *plist, t_slist *slist, va_list *args);
void	ifintegerl(t_plist *plist, t_slist *slist, va_list *args);
char	*integer_plus_long(t_slist *slist, long value);
char	*integer_plus_longlong(t_slist *slist, long long value);

void	ifunsigned(t_plist *plist, t_slist *slist, va_list *args);
void	unsigned_star(t_slist *slist, long value);
char	*unsigned_precision(char *string, t_slist *slist);
void	unsigned_write(t_plist *plist, char *string, t_slist *slist);
char	*unsigned_precision_with_zeros(t_slist *slist, char *string, char *send);
char	*unsigned_write_zeros2(t_slist *slist, char *s, char *string);
void	unsigned_write2(t_plist *plist, char *string);

void	ifunsignedhh(t_plist *plist, t_slist *slist, va_list *args);
void	ifunsignedh(t_plist *plist, t_slist *slist, va_list *args);
void	ifunsignedll(t_plist *plist, t_slist *slist, va_list *args);
void	ifunsignedl(t_plist *plist, t_slist *slist, va_list *args);

void	ifhexadecimallower(t_plist *plist, t_slist *slist, va_list *args);
char	*convert_return_hexadecimallower(unsigned long long int hexadecimal_value, char *send, t_slist *slist);
char	*convert_hexadecimallower_hash(char *string);
char	*reverse_hexadecimallower(char *string, t_slist *slist);
void	hexadecimallower_write(t_plist *plist, char *string, t_slist *slist);
char	*hexadecimallower_precision_with_zeros(t_slist *slist, char *string, char *send);
char	*return_if_one_hexalowerdigit(t_slist *slist, char *send, long long int value);
char	*hexalower_write_zeros2(t_slist *slist, char *send, char *string);

void	ifhexadecimallowerhh(t_plist *plist, t_slist *slist, va_list *args);
void	ifhexadecimallowerh(t_plist *plist, t_slist *slist, va_list *args);
void	ifhexadecimallowerll(t_plist *plist, t_slist *slist, va_list *args);
void	ifhexadecimallowerl(t_plist *plist, t_slist *slist, va_list *args);

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
