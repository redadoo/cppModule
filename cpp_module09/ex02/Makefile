# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 15:54:22 by edoardo           #+#    #+#              #
#    Updated: 2024/02/13 14:49:56 by edoardo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= PmergeMe

CC			= c++ -std=c++98
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

OBJDIR      = .objFiles

FILES		= main PmergeMe

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= PmergeMe.hpp

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

play:re
	@./$(NAME) "11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7"

clean:
	@$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all