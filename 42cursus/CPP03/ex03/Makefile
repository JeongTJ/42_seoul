SRCS := \
	main.cpp \
	ClapTrap.cpp \
	ScavTrap.cpp \
	FragTrap.cpp \
	DiamondTrap.cpp

OBJS := $(SRCS:.cpp=.o)
INCLUDE := .
CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98
NAME := CPP03_ex03

SUBJECTNAME := "cpp_module_03_ex03"
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
	@ $(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp
	@ $(CXX) $(CXXFLAGS) -c $^ -I$(INCLUDE) -o $@

fclean :
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make fclean$(WHITE)"
	@ make clean
	@ rm -rf $(NAME)

clean :
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make clean$(WHITE)"
	@ rm -rf $(OBJS)
