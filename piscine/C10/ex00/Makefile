SRC = ft_display_file.c
OBJ = ft_display_file.o
NAME = ft_display_file
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
