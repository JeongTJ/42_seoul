.DEFAULT_GOAL := all
SRCS = 	main.c \
		hooks.c \
		parse.c \
		parse_list.c \
		parse_entity1.c \
		parse_entity2.c \
		parse_valid_check1.c \
		parse_valid_check2.c \
		utils.c

SRCS_BONUS = $(SRCS:.c=_bonus.c)

OBJS = $(addprefix ./srcs/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix ./srcs_bonus/, $(SRCS_BONUS:.c=.o))
LIBFT_DIR = ./libft
LIBFT_NAME = ft
LIBFT = libft/libft.a
MLX_DIR = ./mlx
MLX = mlx/libmlx.a
MLX_NAME = mlx
HEADER_DIR = ./include
HEADER_BONUS_DIR = ./include_bonus
CC = cc -Wall -Wextra -Werror -fsanitize=address -g
NAME = miniRT
MANDA = .manda
BONUS = .bonus

all :
	@echo "miniRT : make $(NAME)"
	@make $(MANDA)

bonus :
	@echo "miniRT : make BONUS"
	@make $(BONUS)

$(LIBFT) :
	@ echo "miniRT : make $(LIBFT)"
	@ make -C $(LIBFT_DIR) bonus

$(MLX) :
	@ echo "miniRT : make $(MLX)"
	@ make -C $(MLX_DIR)

$(NAME) :
	@ make $(MANDA)

$(MANDA) : $(LIBFT) $(MLX) $(OBJS)
	@ rm -rf $(BONUS)
	@ touch $(MANDA)
	@ $(CC) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -l$(LIBFT_NAME) -L$(MLX_DIR) -l$(MLX_NAME) -framework OpenGL -framework AppKit

$(BONUS) : $(LIBFT) $(MLX) $(OBJS_BONUS)
	@ rm -rf $(MANDA)
	@ touch $(BONUS)
	@ $(CC) -o $(NAME) $(OBJS_BONUS) -L$(LIBFT_DIR) -l$(LIBFT_NAME) -L$(MLX_DIR) -l$(MLX_NAME) -framework OpenGL -framework AppKit

%_bonus.o : %_bonus.c
	@ $(CC) -c $< -I$(LIBFT_DIR) -I$(HEADER_BONUS_DIR) -I$(MLX_DIR) -o $@

%.o : %.c
	@ $(CC) -c $< -I$(LIBFT_DIR) -I$(HEADER_DIR) -I$(MLX_DIR) -o $@

clean :
	@ echo "miniRT : make clean"
	@ rm -f $(OBJS) $(OBJS_BONUS) $(BONUS) $(MANDA)
	@ make -C $(MLX_DIR) fclean
	@ make -C $(LIBFT_DIR) clean

fclean :
	@ echo "miniRT : make fclean"
	@ rm -f $(OBJS) $(NAME) $(OBJS_BONUS) $(BONUS) $(MANDA)
	@ make -C $(LIBFT_DIR) fclean
	@ make -C $(MLX_DIR) clean

re : fclean
	@ echo "miniRT : make re"
	@ make all

.PHONY: all clean fclean re
