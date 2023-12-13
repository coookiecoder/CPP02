CC=c++
CFLAGS= -std=c++98 -Wall -Werror -Wextra

OBJ=main.o Fixed.o
NAME=Fixed

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: clean all fclean re
