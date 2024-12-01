# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 12:05:19 by lalbento          #+#    #+#              #
#    Updated: 2024/12/01 18:27:05 by lalbento         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME = pipex

# Additional library paths (e.g., libft, gnl)
LIBFT = Libft

# Source files and derived object files
SRC = pipex.c pipex_utils.c
OBJ = $(SRC:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Default target
all: $(NAME)

# Link the executable with the required libraries
$(NAME): $(OBJ) 
	@$(MAKE) -s -C $(LIBFT) 
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -lm -o $(NAME)
	@echo "$(NAME) created"

# Rule to compile .c files to .o files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $@"

# Clean up object files
clean:
	@rm -f $(OBJ)
	@$(MAKE) -s -C $(LIBFT) clean
	@echo "Cleaned object files"

# Clean up all generated files (including executable)
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT) fclean
	@echo "Cleaned all generated files"

# Rebuild everything
re: fclean all

# Declare non-file targets
.PHONY: all clean fclean re
