/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 03:51:25 by tisantos          #+#    #+#             */
/*   Updated: 2021/01/20 04:03:48 by tisantos         ###   ########.fr       */
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
# define WIDTH			"123456789" // Acho que tens que adicionar a (*) na função só
# define PRECISION		"." // Acho que tens que adicionar a (*) na função só - Entra conflito
# define LENGTH			"lh"												// com a de cima
# define STAR			"*"


typedef struct 	printf_list
{
	char		*format;
	int			format_length;
	int			format_count;

	char		*final_format;
	int			final_format_lenght;
}				p_list;

typedef struct 	specifiers_list
{
	int			minus;
	int			zero;
	int			space;
	int			hash;
	int			plus;

	int			width;

	int			precision;
	int			precision_error;
	int			star;

	int			length;
}				s_list;


int		ft_printf(const char *format, ...);
void	parse(p_list *plist, va_list *args, s_list *slist);
void	write_character_outside_conversion(p_list *plist, char character, s_list *slist);
int		character_outside_conversion_write_width_greater(p_list *plist, s_list *slist, int i);
int		character_outside_conversion_write_minus_greater(p_list *plist, s_list *slist, int i);

char	*ft_strjoinchr(const char *s1, char s2);

char	*ft_itoa_unsigned(long n);
static	char *ifzero_unsigned(long n);
static	char *iflesszero_unsigned(long n);
static	char *ifmorezero_unsigned(long n);
static	int	length_unsigned(long n);

void	initialize_slist(s_list *slist);
void	initialize_plist(p_list *plist, char *format);


void	conversion(p_list *plist, va_list *args, s_list *slist);

void	ifpercent(p_list *plist, s_list *slist);
void	percent_process(p_list *plist, char character, s_list *slist);
void	percent_write(char character);

void	ifcharacter(p_list *plist, s_list *slist, va_list *args);
void	character_process(p_list *plist, char character, s_list *slist);
int		character_write_width_greater(p_list *plist, s_list *slist, int i);
int		character_write_minus_greater(p_list *plist, s_list *slist, int i);

void	ifstring(p_list *plist, s_list *slist, va_list *args);
char	*string_process(p_list *plist, s_list *slist, char *string);
int		string_write_width_greater(p_list *plist, s_list *slist, int i, int length);
int		string_write_minus_greater(p_list *plist, s_list *slist, int i, int length);
char	*string_precision(s_list *slist, char *string);

void	ifpointer(p_list *plist, s_list *slist, va_list *args);
char	*convert_return_hexadecimal(long long int pointer_value, char *send, s_list *slist);
char	*reverse_hexadecimal(char *string, s_list *slist);
char	*precision_hexadecimal(char *string, s_list *slist);
void	pointer_write(p_list *plist, char *string, s_list *slist);
int		pointer_write_width_greater(p_list *plist, s_list *slist, int i, int length);
int		pointer_write_minus_greater(p_list *plist, s_list *slist, int i, int length);

void	ifdigit(p_list *plist, s_list *slist, va_list *args);
char	*digit_precision(char *string, s_list *slist);
char	*digit_precision_with_error(char *string, s_list *slist);
void	digit_write(p_list *plist, char *string, s_list *slist);
int		digit_write_width_greater(p_list *plist, s_list *slist, int i, int length);
int		digit_write_minus_greater(p_list *plist, s_list *slist, int i, int length);
char	*digit_write_zeros(p_list *plist, s_list *slist, char *string);
char	*digit_precision_with_zeros(s_list *slist, char *string, char *send);

void	ifinteger(p_list *plist, s_list *slist, va_list *args);
char	*integer_precision(char *string, s_list *slist);
char	*integer_precision_with_error(char *string, s_list *slist);
void	integer_write(p_list *plist, char *string, s_list *slist);
int		integer_write_width_greater(p_list *plist, s_list *slist, int i, int length);
int		integer_write_minus_greater(p_list *plist, s_list *slist, int i, int length);
char	*integer_write_zeros(p_list *plist, s_list *slist, char *string);
char	*integer_precision_with_zeros(s_list *slist, char *string, char *send);

void	ifunsigned(p_list *plist, s_list *slist, va_list *args);
char	*unsigned_precision(char *string, s_list *slist);
char	*unsigned_precision_with_error(char *string, s_list *slist);
void	unsigned_write(p_list *plist, char *string, s_list *slist);
int		unsigned_write_width_greater(p_list *plist, s_list *slist, int i, int length);
int		unsigned_write_minus_greater(p_list *plist, s_list *slist, int i, int length);
char	*unsigned_write_zeros(p_list *plist, s_list *slist, char *string);
char	*unsigned_precision_with_zeros(s_list *slist, char *string, char *send);

void	ifhexadecimallower(p_list *plist, s_list *slist, va_list *args);
char	*convert_return_hexadecimallower(long long int hexadecimal_value, char *send, s_list *slist);
char	*reverse_hexadecimallower(char *string, s_list *slist);
char	*precision_hexadecimallower(char *string, s_list *slist);
void	hexadecimallower_write(p_list *plist, char *string, s_list *slist);
int		hexadecimallower_write_width_greater(p_list *plist, s_list *slist, int i, int length);
int		hexadecimallower_write_minus_greater(p_list *plist, s_list *slist, int i, int length);
char	*hexadecimallower_write_zeros(p_list *plist, s_list *slist, char *string);
char	*hexadecimallower_precision_with_zeros(s_list *slist, char *string, char *send);

void	ifhexadecimalupper(p_list *plist, s_list *slist, va_list *args);
char	*convert_return_hexadecimalupper(long long int hexadecimal_value, char *send, s_list *slist);
char	*reverse_hexadecimalupper(char *string, s_list *slist);
char	*precision_hexadecimalupper(char *string, s_list *slist);
void	hexadecimalupper_write(p_list *plist, char *string, s_list *slist);
int		hexadecimalupper_write_width_greater(p_list *plist, s_list *slist, int i, int length);
int		hexadecimalupper_write_minus_greater(p_list *plist, s_list *slist, int i, int length);
char	*hexadecimalupper_write_zeros(p_list *plist, s_list *slist, char *string);
char	*hexadecimalupper_precision_with_zeros(s_list *slist, char *string, char *send);


void	specifier(p_list *plist, va_list *args, s_list *slist);
void	hasflags(p_list *plist, s_list *slist);
void	hasminus(p_list *plist, s_list *slist);
void	haszeros(p_list *plist, s_list *slist);
void	haswidth(p_list *plist, s_list *slist, va_list *args);
void	hasprecision(p_list *plist, s_list *slist, va_list *args);

#endif
