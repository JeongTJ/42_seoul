SRC = ft_cat.c
OBJ = ft_cat.o
NAME = ft_cat
CC = cc -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ) 
	$(CC) $^ -o $@

re : fclean all

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJ)

$(OBJ) : $(SRC)
	$(CC) -c $^
