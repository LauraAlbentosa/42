# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 12:05:19 by lalbento          #+#    #+#              #
#    Updated: 2025/01/29 21:40:58 by lalbento         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME = push_swap

# Additional library paths (e.g., libft, gnl)
LIBFT = ../Libft
LIBFT_A = $(LIBFT)/libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files and derived object files
SRC = push_swap.c stack_utils.c sort_utils.c utils.c manage_stack.c init_sort.c sort_utils_2.c main.c Mov/swap.c Mov/rotate.c Mov/push.c Mov/reverse_rotate.c
OBJ = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Link the executable with the required libraries
$(NAME): $(OBJ) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -o $(NAME) 
	@echo "Executable $(NAME) created"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT)
	@echo "Created Libft library"

# Rule to compile .c files to .o files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $@"

# Clean up object files
clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@$(MAKE) -s -C $(LIBFT) clean
	@echo "Cleaned object files"

# Clean up all generated files (including executable)
fclean: clean
	@rm -f $(NAME)
	@rm -f $(OBJ) $(BONUS_OBJ)
	@$(MAKE) -s -C $(LIBFT) fclean
	@echo "Cleaned all generated files"

# Rebuild everything
re: clean all

# Declare non-file targets
.PHONY: all clean fclean re bonus
