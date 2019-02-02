NAME = fdf
FLAGS = -Wall -Wextra -Werror
SRC =	reader.c \
		main.c 

LIBS = -L libft/  -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -g $(FLAGS) $(LIBS) $(SRC) -I fdf_header.h -o $(NAME)

clean:
	rm -rf $(OBJ)
	make -C libft/ clean

fclean:
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re