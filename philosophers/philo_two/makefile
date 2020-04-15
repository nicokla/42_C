NAME	= philosophers

INCDIR	= ./
SRCDIR	= ./
OBJDIR	= ./

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))
SRC		= main.c ft_atoi.c ft_itoa.c utils.c message.c

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O3

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
