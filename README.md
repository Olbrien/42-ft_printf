# ft_printf
Update: 31-01-2021

Está quase. Falta as conversions bónus "nfge", resto parece estar tudo bem. 

Update: 02-02-2021

Já fizeste o Float para casos normais e arredondados. Vais para o precision agora.

Update: 06-02-2021

Já fizeste o Float para os precisions. Vais agora para os # (altform).

Update: 07-02-2021

Floats já estão bons. Não há ll, l, h, hh de floats. Vais fazer agora a norminette e começar o 'e'.

Update: 13-02-2021

Norminette feita. "l" de 'c' e 's' estão feitos. Não conseguiste fazer o 'g'. Fraco.

./reset-to-default-enabled-tests\
./disable-test notintsubject_o\
./enable-test bonus_length\
./enable-test bonus_af\
./enable-test bonus_sp\
./enable-test bonus_as\
./enable-test "bonus*_f_"\
./enable-test "bonus*_n_"\
./enable-test nocrash\
./disable-test "bonus_notrequired"\
./test


Norme: ./ Makefile 
Warning: Not a valid file
Norme: ./ libft/Makefile 
Warning: Not a valid file
Norme: ./ norminette.txt 
Warning: Not a valid file
Norme: ft_printf2.c
Norme: libft/ft_bzero.c
Norme: libft/ft_isascii.c
Norme: libft/ft_calloc.c
Norme: libft/ft_isalnum.c
Norme: libft/ft_lstdelone.c
Norme: libft/ft_atoi.c
Norme: libft/ft_lstadd_front.c
Norme: libft/ft_isprint.c
Norme: libft/ft_lstadd_back.c
Norme: libft/ft_lstsize.c
Norme: libft/ft_lstlast.c
Norme: libft/ft_lstnew.c
Norme: libft/ft_memchr.c
Norme: libft/ft_putchar_fd.c
Norme: libft/ft_memset.c
Norme: libft/ft_memcpy.c
Norme: libft/ft_putnbr_fd.c
Norme: libft/ft_strdup.c
Norme: libft/ft_strlcpy.c
Norme: libft/ft_itoa.c
Norme: libft/ft_strnstr.c
Norme: libft/ft_strjoin.c
Norme: libft/ft_substr.c
Norme: libft/ft_strrchr.c
Norme: libft/ft_lstmap.c
Norme: libft/ft_memmove.c
Norme: libft/ft_strchr.c
Norme: libft/ft_strncmp.c
Norme: ft_printf.c
Norme: libft/ft_isalpha.c
Norme: libft/ft_lstclear.c
Norme: libft/ft_memccpy.c
Norme: libft/ft_putendl_fd.c
Norme: libft/ft_split.c
Error: global scope bad aligned
Norme: libft/ft_strlcat.c
Norme: libft/ft_strmapi.c
Norme: libft/libft.h
Error: global scope bad aligned
Error (line 20): s_list and t_list not aligned.
Error (line 20): must have only tabulations between struct and s_list.
Norme: libft/ft_toupper.c
Norme: libft/ft_strtrim.c
Error: global scope bad aligned
Norme: sources/conversion2.c
Norme: sources/conversions/ifdigit.c
Norme: sources/conversions/ifdigit3.c
Norme: sources/conversions/iffloat5.c
Norme: sources/conversion.c
Error: global scope bad aligned
Norme: sources/conversions/ifcharacter.c
Error: global scope bad aligned
Norme: sources/conversions/iffloat3.c
Norme: sources/conversions/iffloat.c
Error: global scope bad aligned
Norme: includes/ft_printf.h
Error: global scope bad aligned
Error (line 33): s_printflist and t_plist not aligned.
Error (line 33): must have only tabulations between struct and s_printflist.
Error (line 43): s_specifierslist and t_slist not aligned.
Error (line 43): must have only tabulations between struct and s_specifierslist.
Norme: libft/ft_isdigit.c
Norme: sources/conversions/iffloat2.c
Error: global scope bad aligned
Norme: libft/ft_lstiter.c
Norme: sources/conversions/ifhexadecimallower3.c
Error: global scope bad aligned
Norme: libft/ft_memcmp.c
Norme: sources/conversions/ifn.c
Norme: libft/ft_putstr_fd.c
Norme: libft/ft_strlen.c
Norme: libft/ft_tolower.c
Norme: sources/conversions/ifinteger.c
Norme: sources/conversions/ifhexadecimallower2.c
Error: global scope bad aligned
Norme: sources/conversions/iffloat4.c
Error: global scope bad aligned
Norme: sources/conversions/ifstring2.c
Norme: sources/conversions/ifinteger3.c
Norme: sources/conversions/ifhexadecimalupper3.c
Error: global scope bad aligned
Norme: sources/conversions/ifpointer2.c
Error: global scope bad aligned
Norme: sources/ft_itoa_unsigned_long.c
Error: global scope bad aligned
Norme: sources/conversions/ifunsigned3.c
Norme: sources/specifiers/flags/hasminus.c
Norme: sources/conversions/ifhexadecimalupper2.c
Error: global scope bad aligned
Norme: sources/specifiers/haswidth.c
Error: global scope bad aligned
Norme: sources/conversions/ifhexadecimalupper.c
Error: global scope bad aligned
Norme: sources/conversions/ifstring.c
Error: global scope bad aligned
Norme: sources/conversions/ifdigit2.c
Error: global scope bad aligned
Norme: sources/conversions/lengths/ifcharacterlength.c
Norme: sources/conversions/ifpercent.c
Error: global scope bad aligned
Norme: sources/conversions/lengths/ifdigitlength.c
Norme: sources/conversions/lengths/ifhexadecimalupperlength.c
Norme: sources/conversions/lengths/ifintegerlength2.c
Norme: sources/conversions/ifpointer.c
Error: global scope bad aligned
Norme: sources/conversions/ifunsigned.c
Norme: sources/conversions/lengths/ifdigitlength2.c
Norme: sources/ft_itoa_longlong.c
Error: global scope bad aligned
Norme: sources/initializers.c
Norme: sources/conversions/lengths/ifnlength.c
Norme: sources/specifiers/haslength.c
Norme: sources/conversions/ifhexadecimallower.c
Error: global scope bad aligned
Norme: sources/conversions/lengths/ifintegerlength.c
Norme: sources/conversions/lengths/ifunsignedlength.c
Norme: sources/ft_strjoinchr.c
Norme: sources/conversions/ifunsigned2.c
Error: global scope bad aligned
Norme: sources/ft_itoa_unsigned.c
Error: global scope bad aligned
Norme: sources/specifier.c
Norme: sources/ft_itoa_long.c
Error: global scope bad aligned
Norme: sources/specifiers/hasprecision.c
Error: global scope bad aligned
Norme: sources/specifiers/hasflags.c
Error: global scope bad aligned
Norme: sources/conversions/ifinteger2.c
Error: global scope bad aligned
Norme: sources/conversions/lengths/ifhexadecimallowerlength.c
Norme: sources/conversions/lengths/ifstringlength.c
Norme: sources/ft_itoa_unsigned_longlong.c
Error: global scope bad aligned
Norme: sources/specifiers/flags/haszeros.c
Error: global scope bad aligned
