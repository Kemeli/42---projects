SOURCE = 	ft_printf.c \
			ft_printf_utils.c \
			ft_put_type.c \
			ft_itoas.c \

OBJECTS = 	ft_printf.o \
			ft_printf_utils.o \
			ft_put_type.o \
			ft_itoas.o \

NAME 	= 	libftprintf.a

CFLAGS 	= 	-Wall -Werror -Wextra

.c.o:		$(SOURCE)
			cc $(FLAGS) -c -o $@ $<

$(NAME):	$(OBJECTS)
			ar rcs $@ $^

all: 		$(NAME)

clean:
			rm -f $(OBJECTS)

fclean:		clean
			rm -f $(NAME)

re:			clean all

.PHONY: 	all clean fclean re
