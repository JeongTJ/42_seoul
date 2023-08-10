SRCS_DIR = ./srcs
INCLUDES_DIR = includes
OBJS = ./srcs/ft_putchar.o ./srcs/ft_swap.o ./srcs/ft_putstr.o ./srcs/ft_strlen.o ./srcs/ft_strcmp.o
NAME = libft.a 
CC = cc -Wall -Wextra -Werror

all : $(NAME)

re : fclean all

fclean : clean 
	rm -rf libft.a

clean :
	rm -rf $(OBJS)

$(NAME) : $(OBJS)
	ar rc $@ $(OBJS)

%.o : %.c ./$(INCLUDES_DIR)/ft.h
	$(CC) -c $< -I$(INCLUDES_DIR) -o $@
