NAME = libftprintf.a
SRCS = ft_printf.c ft_putstr_fd.c pr_putchar.c pr_putnbr.c pr_putpointer.c pr_putstr.c pr_unsbase.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	ar	-rcs $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all re clean fclean