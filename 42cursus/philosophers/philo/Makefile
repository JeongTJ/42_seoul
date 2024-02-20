.DEFAULT_GOAL := all

PHILO_SRCS = \
			init.c \
			main.c \
			parser.c \
			utils1.c \
			utils2.c \
			utils3.c \
			utils4.c

PHILO_OBJS = $(addprefix ./srcs/, $(PHILO_SRCS:.c=.o))
OBJS = $(PHILO_OBJS)

HEADER_DIR = ./header
CC = cc -Wall -Wextra -Werror -g -fsanitize=thread
NAME = philo

all :
	@echo "philosophers : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -I$(HEADER_DIR)

%_bonus.o : %_bonus.c
	@$(CC) -c $< -I$(HEADER_BONUS_DIR) -o $@

%.o : %.c
	@$(CC) -c $< -I$(HEADER_DIR) -o $@

clean :
	@echo "philosophers : make clean"
	@rm -f $(OBJS) $(NAME)

fclean :
	@echo "philosophers : make fclean"
	@rm -f $(OBJS) $(NAME)

re : fclean
	@echo "philosophers : make re"
	@make all

.PHONY: all clean fclean re
