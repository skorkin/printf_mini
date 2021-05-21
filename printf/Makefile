LIBSRC = ft_printf.c ft_valuetype.c ft_utils.c ft_useparameters.c ft_stringtype.c ft_parser.c ft_definerules.c ft_numcount.c ft_putnbr.c ft_useparameters_2.c
NAME = libftprintf.a
CC = gcc
LIBOBJS = ${LIBSRC:.c=.o}
CFLAGS  = -Wall -Werror -Wextra -g
%.o: %.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
all:	$(NAME)
$(NAME):$(LIBOBJS)
		ar rc $(NAME) $(LIBOBJS)
		ranlib $(NAME)
clean:
		rm -f *.o
fclean: clean
		rm -f $(NAME)
re: fclean all