name = fdf
FLAGS = -Wall -Wextra -Werror
SRC = main.c
LIBS = 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	gcc -g $(FLAGS)
