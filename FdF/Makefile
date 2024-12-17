# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 12:05:19 by lalbento          #+#    #+#              #
#    Updated: 2024/12/17 19:19:05 by lalbento         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME = fdf

# MLX library path
MLX = minilibx-linux
MLX_A = $(MLX)/libmlx.a

# Additional library paths (e.g., libft, gnl)
LIBFT = Libft
LIBFT_A = $(LIBFT)/libft.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files and derived object files
SRC = fdf.c parsing.c draw_line.c utils.c transform_points.c colors.c controls.c
OBJ = $(SRC:.c=.o)

#Bonus files
BONUS = 
BONUS_OBJ = $(BONUS:.c=.o)

# Default target
all: $(NAME)

# Link the executable with the required libraries
$(NAME): $(OBJ) $(MLX_A) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(MLX) -lmlx -lm -lXext -lX11 -lz -o $(NAME) 
	@echo "Executable $(NAME) created"

$(MLX_A):
	@$(MAKE) -C $(MLX)
	@echo "Created Mlx library"

$(LIBFT_A):
	@$(MAKE) -C $(lIBFT)
	@echo "Created Libft library"

# Rule to compile .c files to .o files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $@"

# Clean up object files
clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@$(MAKE) -s -C $(MLX) clean
	@$(MAKE) -s -C $(LIBFT) clean
	@echo "Cleaned object files"

# Clean up all generated files (including executable)
fclean: clean
	@rm -f $(NAME)
	@rm -f $(OBJ) $(BONUS_OBJ)
	@$(MAKE) -s -C $(MLX) fclean
	@$(MAKE) -s -C $(LIBFT) fclean
	@echo "Cleaned all generated files"

# Rebuild everything
re: clean all

#It compiles the bonus files avoiding relink with the bonus.bonus file
bonus: bonus.bonus
bonus.bonus:$(BONUS_OBJ) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	touch bonus.bonus
	@echo "$(NAME) created and indexed with bonus"

# Declare non-file targets
.PHONY: all clean fclean re bonus
