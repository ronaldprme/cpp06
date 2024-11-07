# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 17:33:20 by rprocopi          #+#    #+#              #
#    Updated: 2024/11/07 18:05:29 by rprocopi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		ScalarConverter

SOURCE			=		main.cpp \
						ScalarConverter.cpp

OBJECT			= 		$(SOURCE:.cpp=.o)

COMPILE			=		g++

FLAGS			=		-Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp
	@echo "Compiling ......    			$<"
	@$(COMPILE) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	@$(COMPILE) $(FLAGS) $(OBJECT) -o $(NAME) 
	@echo "Executable			./$(NAME)"


clean:
	@/bin/rm -f $(OBJECT)

fclean: clean
	@/bin/rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re


