SRC_DIR =	fdf.c fdf_draw1.c fdf_draw2.c fdf_key_move.c fdf_parsing.c \
			fdf_utils1.c fdf_utils2.c
SRCS = $(addprefix ./srcs/,$(notdir $(SRC_DIR)))
OBJS = $(SRCS:.c=.o)
HEADERS = fdf.h
HEADER_DIR = ./header
LIBFT = ./libft/libft.a
NAME = fdf
MLX_DIR = mlx

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAG = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

re : fclean all

fclean : clean
	make -C libft fclean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJS)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAG) -Llibft -lft $(OBJS) -o $@

%.o : %.c $(HEADER_DIR)/$(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C libft bonus

.PHONY: all bonus clean fclean re
