.DEFAULT_GOAL := all
SRCS = pipex.c error.c parsing.c cmd_split.c process.c
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
CC = cc -Wall -Wextra -Werror -MMD -MP
NAME = pipex
MANDA = .manda
BONUS = .bonus
-include $(DEPS)

all :
	@echo "pipex : make $(NAME)"
	@make $(MANDA)

bonus :
	@echo "pipex : make BONUS"
	@make $(BONUS)

$(LIBFT) :
	@ echo "pipex : make $(LIBFT)"
	@ make -C $(LIBFT_DIR) bonus

$(NAME) : $(LIBFT) $(OBJS)
	@make $(MANDA)

$(MANDA) : $(LIBFT) $(OBJS)
	@rm -rf $(BONUS)
	@touch $(MANDA)
	@$(CC) -o $(NAME) $(OBJS) -l$(LIBFT_NAME) -L$(LIBFT_DIR) -I$(LIBFT_DIR) -I$(HEADER_DIR)

$(BONUS) : $(LIBFT) $(OBJS_BONUS)
	@rm -rf $(MANDA)
	@touch $(BONUS)
	@$(CC) -o $(NAME) $(OBJS_BONUS) -l$(LIBFT_NAME) -L$(LIBFT_DIR) -I$(LIBFT_DIR) -I$(HEADER_BONUS_DIR)

%.o : %.c
	@$(CC) -c $<  -I$(LIBFT_DIR) -o $@

clean :
	@echo "pipex : make clean"
	@rm -f $(OBJS) $(DEPS) $(OBJS_BONUS) $(BONUS) $(MANDA) $(DEPS_BONUS)
	@make -C $(LIBFT_DIR) clean

fclean :
	@echo "pipex : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS) $(OBJS_BONUS) $(BONUS) $(MANDA) $(DEPS_BONUS)
	@make -C $(LIBFT_DIR) fclean

re : fclean
	@ echo "pipex : make re"
	@make all

.PHONY: all clean fclean re
