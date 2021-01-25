NAME = libftprintf.a

SOURCES = 	ft_printf.c\
			\
			sources/initializers.c\
			sources/ft_strjoinchr.c\
			sources/ft_itoa_unsigned.c\
			\
			sources/conversion.c\
			sources/conversions/ifpercent.c\
			sources/conversions/ifcharacter.c\
			sources/conversions/ifstring.c\
			sources/conversions/ifpointer.c\
			sources/conversions/ifpointer2.c\
			sources/conversions/ifdigit.c\
			sources/conversions/ifdigit2.c\
			sources/conversions/ifdigit3.c\
			sources/conversions/ifinteger.c\
			sources/conversions/ifinteger2.c\
			sources/conversions/ifinteger3.c\
			sources/conversions/ifunsigned.c\
			sources/conversions/ifunsigned2.c\
			sources/conversions/ifunsigned3.c\
			sources/conversions/ifhexadecimallower.c\
			sources/conversions/ifhexadecimallower2.c\
			sources/conversions/ifhexadecimallower3.c\
			sources/conversions/ifhexadecimalupper.c\
			sources/conversions/ifhexadecimalupper2.c\
			sources/conversions/ifhexadecimalupper3.c\
			\
			sources/specifier.c\
			sources/specifiers/hasflags.c\
			sources/specifiers/flags/hasminus.c\
			sources/specifiers/flags/haszeros.c\
			sources/specifiers/haswidth.c\
			sources/specifiers/hasprecision.c\
			sources/specifiers/haslength.c

OBJS = $(SOURCES:.c=.o)

CC = gcc
RM = rm -f
FLAGS = -c # -c -Wall -Wextra -Werror <-- Voltar a por isto
INCLUDES = -I./includes

all : $(NAME)

$(NAME) :	$(OBJS)
			$(MAKE) bonus -C ./libft
			cp libft/libft.a $(NAME)
			$(CC) $(FLAGS) $(INCLUDES) $(SOURCES)
			ar -rcs $(NAME) $(OBJS)

clean :
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)

fclean :
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re :		fclean all
