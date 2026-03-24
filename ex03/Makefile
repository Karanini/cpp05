# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 14:08:56 by bkaras-g          #+#    #+#              #
#    Updated: 2026/03/24 16:43:40 by michel_32        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = intern

SRC = ../ex02/Bureaucrat.cpp \
		../ex02/AForm.cpp \
		../ex02/ShrubberyCreationForm.cpp \
		../ex02/RobotomyRequestForm.cpp \
		../ex02/PresidentialPardonForm.cpp \
		Intern.cpp \
		main.cpp

HEADERS = ../ex02/Bureaucrat.hpp \
			../ex02/ShrubberyCreationForm.hpp \
			../ex02/RobotomyRequestForm.hpp \
			../ex02/PresidentialPardonForm.hpp \
			../ex02/AForm.hpp \
			Intern.hpp

RM = rm -f
OBJ := $(patsubst %.cpp, %.o, $(SRC))
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) Makefile
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo  "Mandatory part compilation ok"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -I. -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo  "Clean done"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

dev: all clean

.PHONY: all clean fclean re dev
