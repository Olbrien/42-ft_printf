NAME = libftprintf.a

SOURCES = 	ft_printf.c\
			ft_printf2.c\
			\
			sources/initializers.c\
			sources/ft_strjoinchr.c\
			sources/ft_itoa_unsigned.c\
			sources/ft_itoa_unsigned_long.c\
			sources/ft_itoa_unsigned_longlong.c\
			sources/ft_itoa_long.c\
			sources/ft_itoa_longlong.c\
			\
			sources/conversion.c\
			sources/conversion2.c\
			sources/ifpercent.c\
			sources/ifcharacter.c\
			sources/ifstring.c\
			sources/ifstring2.c\
			sources/ifpointer.c\
			sources/ifpointer2.c\
			sources/ifdigit.c\
			sources/ifdigit2.c\
			sources/ifdigit3.c\
			sources/ifinteger.c\
			sources/ifinteger2.c\
			sources/ifinteger3.c\
			sources/ifunsigned.c\
			sources/ifunsigned2.c\
			sources/ifunsigned3.c\
			sources/ifhexadecimallower.c\
			sources/ifhexadecimallower2.c\
			sources/ifhexadecimallower3.c\
			sources/ifhexadecimalupper.c\
			sources/ifhexadecimalupper2.c\
			sources/ifhexadecimalupper3.c\
			sources/ifn.c\
			sources/iffloat.c\
			sources/iffloat2.c\
			sources/iffloat3.c\
			sources/iffloat4.c\
			sources/iffloat5.c\
			sources/ifexponent.c\
			sources/ifexponent2.c\
			sources/ifexponent3.c\
			sources/ifexponent4.c\
			sources/ifexponent5.c\
			sources/ifexponent6.c\
			sources/ifexponent7.c\
			\
			sources/ifdigitlength.c\
			sources/ifdigitlength2.c\
			sources/ifintegerlength.c\
			sources/ifintegerlength2.c\
			sources/ifunsignedlength.c\
			sources/ifhexadecimallowerlength.c\
			sources/ifhexadecimalupperlength.c\
			sources/ifnlength.c\
			sources/ifstringlength.c\
			sources/ifcharacterlength.c\
			\
			sources/specifier.c\
			sources/hasflags.c\
			sources/hasminus.c\
			sources/haszeros.c\
			sources/haswidth.c\
			sources/hasprecision.c\
			sources/haslength.c

SOURCES_O = initializers.o\
			ft_strjoinchr.o\
			ft_itoa_unsigned.o\
			ft_itoa_unsigned_long.o\
			ft_itoa_unsigned_longlong.o\
			ft_itoa_long.o\
			ft_itoa_longlong.o\
			\
			conversion.o\
			conversion2.o\
			ifpercent.o\
			ifcharacter.o\
			ifstring.o\
			ifstring2.o\
			ifpointer.o\
			ifpointer2.o\
			ifdigit.o\
			ifdigit2.o\
			ifdigit3.o\
			ifinteger.o\
			ifinteger2.o\
			ifinteger3.o\
			ifunsigned.o\
			ifunsigned2.o\
			ifunsigned3.o\
			ifhexadecimallower.o\
			ifhexadecimallower2.o\
			ifhexadecimallower3.o\
			ifhexadecimalupper.o\
			ifhexadecimalupper2.o\
			ifhexadecimalupper3.o\
			ifn.o\
			iffloat.o\
			iffloat2.o\
			iffloat3.o\
			iffloat4.o\
			iffloat5.o\
			ifexponent.o\
			ifexponent2.o\
			ifexponent3.o\
			ifexponent4.o\
			ifexponent5.o\
			ifexponent6.o\
			ifexponent7.o\
			\
			ifdigitlength.o\
			ifdigitlength2.o\
			ifintegerlength.o\
			ifintegerlength2.o\
			ifunsignedlength.o\
			ifhexadecimallowerlength.o\
			ifhexadecimalupperlength.o\
			ifnlength.o\
			ifstringlength.o\
			ifcharacterlength.o\
			\
			specifier.o\
			hasflags.o\
			hasminus.o\
			haszeros.o\
			haswidth.o\
			hasprecision.o\
			haslength.o

OBJS = $(SOURCES:.c=.o)

CC = gcc
RM = rm -f
FLAGS = -c -Wall -Wextra -Werror
INCLUDES = -I./includes

all : $(NAME)

$(NAME) :	$(OBJS)
			$(MAKE) bonus -C ./libft
			cp libft/libft.a $(NAME)
			$(CC) $(FLAGS) $(INCLUDES) $(SOURCES)
			ar -rcs $(NAME) $(OBJS)

clean :
			$(MAKE) clean -C ./libft
			$(RM) $(SOURCES_O)
			$(RM) $(OBJS)

fclean :
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re :		fclean all
