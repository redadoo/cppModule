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

NAME 		= Bureaucrat

CC			= g++ -std=c++98
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

OBJDIR      = .objFiles

FILES		= main AForm Bureaucrat PresidentialPardonForm RobotomyRequestForm ShrubberyCreationForm

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= AForm.hpp Bureaucrat.hpp  PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

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

clean:
	@$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all