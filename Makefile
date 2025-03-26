# fractol
NAME		=	fractol
SRCS		=	main.c draw_shape.c fromLibft.c key_mouse.c check_argv.c
OBJS 		=	$(SRCS:%.c=%.o)
# Compiler
CC			=	cc
LIBX_FLAGS	=	mlx_linux/libmlx.a -lXext -lX11 -lm
CFLAGS		=	-Wall -Wextra -Werror -O2
LIB_PRINTF_DIR = ft_printf
LIB_PRINTF = $(LIB_PRINTF_DIR)/libftprintf.a
# Header
HEADERS = fractol.h

# Rules
all:		$(NAME)

# Library target
$(LIB_PRINTF):
	$(MAKE) -C $(LIB_PRINTF_DIR)

$(NAME):	$(OBJS) $(LIB_PRINTF)
			$(CC) $(OBJS) $(LIB_PRINTF) $(LIBX_FLAGS) -o $(NAME)

%.o: %.c $(HEADERS)
		 $(CC) $(CFLAGS) -Imlx_linux -c $< -o $@

clean:
			$(RM) $(OBJS)
			$(MAKE) -C $(LIB_PRINTF_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIB_PRINTF_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
