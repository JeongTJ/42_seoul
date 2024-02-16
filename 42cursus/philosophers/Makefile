.DEFAULT_GOAL := all

PHILO_SRCS = \
			main.c \
			parser.c \
			utils1.c \
			utils2.c

PHILO_BONUS_SRCS = $(PHILO_SRCS:.c=_bonus.c)

PHILO_OBJS = $(addprefix ./philo/srcs/, $(PHILO_SRCS:.c=.o))
OBJS = $(PHILO_OBJS)

PHILO_BONUS_OBJS = $(addprefix ./philo_bonus/srcs/, $(PHILO_BONUS_SRCS:.c=.o))
OBJS_BONUS = $(PHILO_BONUS_OBJS)

HEADER_DIR = ./philo/header
HEADER_BONUS_DIR = ./philo_bonus/header
CC = cc -Wall -Wextra -Werror
NAME = philo
BONUS_NAME = philo_bonus

all :
	@echo "philosophers : make $(NAME)"
	@make $(NAME)

bonus :
	@echo "philosophers : make BONUS"
	@make $(BONUS_NAME)

$(NAME) : $(OBJS)
	@rm -rf $(BONUS_NAME)
	@$(CC) -o $(NAME) $(OBJS) -I$(HEADER_DIR)

$(BONUS_NAME) : $(OBJS_BONUS)
	@rm -rf $(NAME)
	@$(CC) -o $(BONUS_NAME) $(OBJS_BONUS) -I$(HEADER_BONUS_DIR)

%_bonus.o : %_bonus.c
	@$(CC) -c $< -I$(HEADER_BONUS_DIR) -o $@

%.o : %.c
	@$(CC) -c $< -I$(HEADER_DIR) -o $@

clean :
	@echo "philosophers : make clean"
	@rm -f $(OBJS) $(OBJS_BONUS) $(BONUS_NAME) $(NAME)

fclean :
	@echo "philosophers : make fclean"
	@rm -f $(OBJS) $(OBJS_BONUS) $(BONUS_NAME) $(NAME)

re : fclean
	@echo "philosophers : make re"
	@make all

.PHONY: all clean fclean re
