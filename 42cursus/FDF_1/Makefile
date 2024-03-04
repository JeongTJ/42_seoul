.DEFAULT_GOAL := all
SRCS = fdf_main.c fdf_draw1.c fdf_draw2.c fdf_key_move.c fdf_parsing.c \
		fdf_utils.c fdf_axis.c fdf_rotate.c fdf_init.c \
		fdf_hook1.c fdf_hook2.c fdf_box.c fdf_shape.c
SRCS_BONUS = $(SRCS:.c=_bonus.c)
LIBFT_DIR = ./libft
LIBFT_NAME = ft
LIBFT = libft/libft.a
OBJS = $(addprefix ./srcs/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix ./srcs_bonus/, $(SRCS_BONUS:.c=.o))
DEPS = $(addprefix ./srcs/, $(SRCS:.c=.d))
DEPS_BONUS = $(addprefix ./srcs_bonus/, $(SRCS_BONUS:.c=.d))
HEADER_DIR = ./header
HEADER_BONUS_DIR = ./header_bonus
CC = cc -Wall -Wextra -Werror -O3
MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit
NAME = fdf
MANDA = .manda
BONUS = .bonus
-include $(DEPS)

all :
	@echo "FDF : make $(NAME)"
	@make $(MANDA)

bonus :
	@echo "FDF : make BONUS"
	@make $(BONUS)

$(LIBFT) :
	@ echo "FDF : make $(LIBFT)"
	@ make -C $(LIBFT_DIR) bonus

$(NAME) : $(LIBFT) $(OBJS)
	@make $(MANDA)

$(MANDA) : $(LIBFT) $(OBJS)
	@rm -rf $(BONUS)
	@touch $(MANDA)
	@$(CC) -o $(NAME) $(OBJS) -l$(LIBFT_NAME) -L$(LIBFT_DIR) -I$(LIBFT_DIR) -I$(HEADER_DIR) $(MLX)

$(BONUS) : $(LIBFT) $(OBJS_BONUS)
	@rm -rf $(MANDA)
	@touch $(BONUS)
	@$(CC) -o $(NAME) $(OBJS_BONUS) -l$(LIBFT_NAME) -L$(LIBFT_DIR) -I$(LIBFT_DIR) -I$(HEADER_BONUS_DIR) $(MLX)

%.o : %.c
	@$(CC) -c $<  -I$(LIBFT_DIR) -o $@

clean :
	@echo "FDF : make clean"
	@rm -f $(OBJS) $(DEPS) $(OBJS_BONUS) $(BONUS) $(MANDA) $(DEPS_BONUS)
	@make -C $(LIBFT_DIR) clean

fclean :
	@echo "FDF : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS) $(OBJS_BONUS) $(BONUS) $(MANDA) $(DEPS_BONUS)
	@make -C $(LIBFT_DIR) fclean

re : fclean
	@ echo "FDF : make re"
	@make all

.PHONY: all clean fclean re
