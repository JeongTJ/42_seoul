SRC = ft_hexdump.c ft_is_c.c ft_print.c ft_str.c ft_print_hex.c
OBJ = ft_hexdump.o ft_is_c.o ft_print.o ft_str.o ft_print_hex.o
NAME = ft_hexdump
CC = cc -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $^ -o $@

re : fclean all

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJ) ft_ex03.h.gch

%.o : %.c
	$(CC) -c $^ ft_ex03.h
