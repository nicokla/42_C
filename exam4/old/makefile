NAME	= microshell
SRC		= mainNew.c
CFLAG	= -g -Wall -Werror -Wextra -DTEST_SH

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAG) $(SRC) $^ -o $(NAME)

%.o: %.cpp
	gcc -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all test
