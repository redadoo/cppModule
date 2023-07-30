# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 16:12:59 by edoardo           #+#    #+#              #
#    Updated: 2023/07/24 20:30:41 by edoardo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp Phonebook.cpp Contact.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= g++
RM				= rm -rf
CXXFLAGS		= -Wall -Wextra -Werror -I.

NAME			= main

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
				$(RM) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

exe: all
	./$(NAME)

.PHONY:			all clean fclean re