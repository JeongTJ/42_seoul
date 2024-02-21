.DEFAULT_GOAL := all

PHILO_SRCS = \
			main.c

PHILO_OBJS = $(addprefix ./srcs/, $(PHILO_SRCS:.c=.o))
OBJS = $(PHILO_OBJS)

HEADER_DIR = ./header
CC = cc -Wall -Wextra -Werror
NAME = minirt

all :
	@echo "miniRT : make $(NAME)"
	@make $(NAME)

$(NAME) : $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -I$(HEADER_DIR)

%_bonus.o : %_bonus.c
	@$(CC) -c $< -I$(HEADER_BONUS_DIR) -o $@

%.o : %.c
	@$(CC) -c $< -I$(HEADER_DIR) -o $@

clean :
	@echo "miniRT : make clean"
	@rm -f $(OBJS) $(NAME)

fclean :
	@echo "miniRT : make fclean"
	@rm -f $(OBJS) $(NAME)

re : fclean
	@echo "miniRT : make re"
	@make all

.PHONY: all clean fclean re
