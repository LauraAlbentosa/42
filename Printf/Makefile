#Name of the file
NAME = ft_printf.c

#Source files
SRC = ft_printf.c ft_putstr.c ft_puthcar.c ft_putnbr.c

#Files .o
OBJ = $(SRC:.c=.o)

#Compilation variables
CC = cc
FLAGS = -Wall -Wextra -Werror

#Bonus source files
BONUS = 

#bonus files .o
BONUS_OBJ = $(BONUS:.c=.o)

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
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo "OBJ cleaned"

#It cleans everythign including the library 
fclean: clean
	@rm -f $(NAME)
	@rm -f $(OBJ) $(BONUS_OBJ) bonus.bonus
	@echo "All objects and executble cleaned"

#Cleans 
re: fclean all

#It compiles the bonus files avoiding relink with the bonus.bonus file
bonus: bonus.bonus
bonus.bonus:$(BONUS_OBJ) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	touch bonus.bonus
	@echo "$(NAME) created and indexed with bonus"

#It indicates which terms are commands
.PHONY: all clean fclean re bonus
