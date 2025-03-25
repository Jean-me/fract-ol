# minilibx_test
NAME		=	fract-ol.out
SRCS		=	main.c draw_shape.c fromLibft.c key_mouse.c
OBJS 		=	$(SRCS:%.c=%.o)
# Compiler
CC			=	gcc
LIBX_FLAGS	=	mlx_linux/libmlx.a -lXext -lX11 -lm
CFLAGS		=	-Wall -Wextra -Werror -O2
# Header
HEADERS = fract-ol.h

# Rules
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(LIBX_FLAGS) -o $(NAME)

%.o: %.c $(HEADERS)
		 $(CC) $(CFLAGS) -Imlx_linux -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
