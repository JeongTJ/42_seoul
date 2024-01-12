SRCFILE =	fdf_main.c fdf_draw1.c fdf_draw2.c fdf_key_move.c fdf_parsing.c \
			fdf_utils.c fdf_axis.c fdf_error.c fdf_rotate.c fdf_init.c \
			fdf_hook1.c fdf_hook2.c fdf_box.c fdf_circle.c
SRCS = $(addprefix ./srcs/,$(notdir $(SRCFILE)))
BONUS_SRCS = $(addprefix ./srcs_bonus/,$(notdir $(SRCFILE)))
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=_bonus.o)

HEADERS = fdf.h
HEADER_DIR = ./header
LIBFT = ./libft/libft.a
NAME = fdf
MLX_DIR = mlx

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAG = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit


ifdef WITH_BONUS
	TARGET_OBJS = $(BONUS_OBJS)
else
	TARGET_OBJS = $(OBJS)
endif

all : $(NAME)

re : fclean all

fclean : clean
	rm -rf $(NAME)

clean :
	make -C libft fclean
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

$(NAME) : $(LIBFT) $(TARGET_OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAG) -Llibft -lft $(TARGET_OBJS) -o $@

%.o : %.c $(HEADER_DIR)/$(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C libft bonus

bonus :
	make WITH_BONUS=1 all

k :
	echo $(TARGET_OBJS)

.PHONY: all bonus clean fclean re
