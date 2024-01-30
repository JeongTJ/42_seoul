SRC = ft_tail.c ft_atoi.c ft_print_tail.c
OBJ = ft_tail.o ft_atoi.o ft_print_tail.o
NAME = ft_tail
CC = cc -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ) 
	$(CC) $^ -o $@

re : fclean all

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJ) ft_ex02.h.gch

%.o : %.c
	$(CC) -c $^ ft_ex02.h
