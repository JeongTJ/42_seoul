SRCS := \
	main.cpp \
	Contract.cpp \
	PhoneBook.cpp

OBJS := $(SRCS:.cpp=.o)
INCLUDE :=
CPP := g++ 
FLAGS := -Wall -Werror -Wextra -std=c++98
NAME := phonebook

SUBJECTNAME := "cpp_module_00_ex00"
RED := \033[31m
GREEN := \033[32m
BLUE := \033[34m
WHITE := \033[0m

.PHONY: all clean fclean re

all :
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make all$(WHITE)"
	@ make $(NAME)

re : fclean all
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make re$(WHITE)"

$(NAME) : $(OBJS)
	@ $(CPP) $(FLAGS) $^ -o $@

%.o : %.cpp
	@ $(CPP) $(FLAGS) -c $^ -I. -o $@

fclean :
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make fclean$(WHITE)"
	@ make clean
	@ rm -rf $(NAME)

clean :
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make clean$(WHITE)"
	@ rm -rf $(OBJS)
