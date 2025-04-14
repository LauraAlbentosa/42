# Name of the exectubale created
NAME = fdf

# MLX path
MLX = minilibx-linux
MLX_A = $(MLX)/libmlx.a

# LIBFT path
LIBFT = Libft
LIBFT_A = $(LIBFT)/libft.a

# Compiler and flags
CC = gcc #gcc o cc??
CFLAGS = -Wall -Wextra -Werror

# Source files and object files
SRC = fdf.c parsing.c drawing.c utils.c colors.c controls.c trasnform.c
OBJ = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Link and compile
$(NAME): $(OBJ) $(MLX_A) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(MLX) -lmlx -lm -lX11 -lz -o $(NAME)
	@echo "$(NAME) created"

$(MLX_A):
	@$(MAKE) -C $(MLX)
	@echo "Mlx library created"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT)
	@echo "Libft library created"

# Rule to compile .c files to .o 
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

# Declare non-file targets
.PHONY: all clean fclean re bonus