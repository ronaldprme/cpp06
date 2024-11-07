# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 19:20:17 by rprocopi          #+#    #+#              #
#    Updated: 2024/11/07 19:28:15 by rprocopi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Serializer		

SOURCE			= 	main.cpp\
					Serializer.cpp

OBJECT			=	$(SOURCE:.cpp=.o)

COMPILE			= 	g++

FLAGS			= 	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp
	@echo "Compiling ....			$<"
	@$(COMPILE) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	@$(COMPILE) $(FLAGS) $(OBJECT) -o $(NAME)
	@echo "Executable 			./$(NAME)"
	
clear:
	@bin/rm -f $(OBJECT)
	
fclean: clean
	@bin/rm -f $(NAME)

re: fclean all

.PHONE: all clear fclean re 