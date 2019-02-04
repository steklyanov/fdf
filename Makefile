NAME = fdf
FLAGS = -Wall -Wextra -Werror
SRC =	reader.c \
		drawing.c \
		main.c 

LIBS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -g $(FLAGS) $(LIBS) $(SRC) libft/libft.a -I libft -I fdf_header.h -o $(NAME)


clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re