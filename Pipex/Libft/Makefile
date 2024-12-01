# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 12:05:19 by lalbento          #+#    #+#              #
#    Updated: 2024/11/29 16:32:36 by lalbento         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of the library
NAME = libft.a

#Source files
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
      ft_isdigit.c ft_isprint.c ft_calloc.c ft_memchr.c ft_memcmp.c \
      ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
      ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
      ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
      ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

#Files .o
OBJ = $(SRC:.c=.o)

#Compilation variables
CC = cc
FLAGS = -Wall -Wextra -Werror -fPIC

#Bonus source files
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

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
