# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalbento <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 15:15:32 by lalbento          #+#    #+#              #
#    Updated: 2024/11/13 11:00:43 by lalbento         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of the file
NAME = libftprintf.a

#Source files
SRC = ft_printf.c ft_putstr.c ft_putchar.c ft_putnbr.c ft_puthex.c ft_putptr.c ft_putunsigned.c

#Files .o
OBJ = $(SRC:.c=.o)

#Compilation variables
CC = cc
FLAGS = -Wall -Wextra -Werror

#Rule to generate the library
all: $(NAME)

#It creates the program only when changes have been made to the files
$(NAME): $(OBJ)
	@ar rcs $(NAME) $?
	@echo "$(NAME) created and indexed"

#It creates .o files
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

#It cleans .o files
clean:
	@rm -f $(OBJ) 
	@echo "OBJ cleaned"

#It cleans everythign including the library 
fclean: clean
	@rm -f $(NAME)
	@rm -f $(OBJ) 
	@echo "All objects and executble cleaned"

#Cleans 
re: fclean all

#It indicates which terms are commands
.PHONY: all clean fclean re 
