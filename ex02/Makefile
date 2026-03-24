# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 14:08:56 by bkaras-g          #+#    #+#              #
#    Updated: 2026/03/24 13:14:00 by michel_32        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = bureaucrat_signing_forms

SRC = Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		main.cpp

HEADERS = Bureaucrat.hpp \
			ShrubberyCreationForm.hpp \
			RobotomyRequestForm.hpp \
			PresidentialPardonForm.hpp \
			AForm.hpp

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
