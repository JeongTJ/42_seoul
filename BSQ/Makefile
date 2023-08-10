SRC = ft_big_square.c ft_print.c ft_str.c ft_split.c ft_read.c ft_is_valid.c main.c
OBJ = ft_big_square.o ft_print.o ft_str.o ft_split.o ft_read.o ft_is_valid.o main.o
HEADER = ft_bsq.h
NAME = ft_bsq
CC = cc -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $^ -o $@

re : fclean all

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJ) $(HEADER).gch

%.o : %.c
	$(CC) -c $^ $(HEADER)
