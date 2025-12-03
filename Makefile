##
## EPITECH PROJECT, 2025
## Minishell
## File description:
## Makefile
##

INCLUDE_DIR = ./include
CPPFLAGS = -I $(INCLUDE_DIR)
CFLAGS = -Wall -Wextra -W -g3
NAME = asm
SRC_DIR = ./src
SRC = $(shell find $(SRC_DIR) -name '*.c')
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
# Updated flags
