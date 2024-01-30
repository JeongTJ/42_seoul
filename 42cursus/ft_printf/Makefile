SRCS =	ft_printf.c ft_printf_utils1.c ft_printf_utils2.c ft_printf_utils3.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

re : fclean all

fclean : clean
	make -C libft fclean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJS) $(OBJS_BNS) ft_printf.h.gch

$(NAME) : $(LIBFT) $(OBJS)
	ar rsc $@ $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C libft bonus
	cp ./libft/libft.a $(NAME)

.PHONY: all bonus clean fclean re
