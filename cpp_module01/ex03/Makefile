# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 11:58:27 by edoardo           #+#    #+#              #
#    Updated: 2024/02/20 15:23:04 by edoardo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= human

CC			= c++ -std=c++98
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

OBJDIR      = .objFiles

FILES		= main HumanA HumanB Weapon 

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= Weapon.hpp HumanB.hpp HumanA.hpp

NONE="\033[0m"
GREEN="\033[32m"
GRAY="\033[2;37m"
CURSIVE="\033[3m"
YELLOW=	"\033[1;33"

.PHONY: all clean fclean re leaks

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@echo $(CURSIVE) $(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC)  $(FLAGS) $(OBJ) $(OPTS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

compile_and_run: re
	@./$(NAME)

run:
	@./$(NAME)

leaks:
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

clean:
	@$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all