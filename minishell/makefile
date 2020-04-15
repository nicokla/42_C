
NAME	= minishell

SRC		=	hash.c path_bin.c pipes.c env.c \
			utils.c redirect.c exec.c cmd.c exit.c\
			utils2.c get_next_line.c builtins.c \
			main.c cd.c pwd.c echo.c export.c unset.c \
			substitutions.c get_argv.c static_var.c \
			substitutions2.c fatal_error.c
OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

FT		= ./libft/
FT_SRC = $(wildcard $(FT)*.c)
FT_LIB	= $(addprefix $(FT),libft.a)
FT_OBJ = $(patsubst %.c, %.o, $(FT_SRC))
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft -l pthread

SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./objs/
LIBDIR	= ./
INCLUDES = -I$(FT) -I$(INCDIR)

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_LIB):
	make -C $(FT) bonus

$(NAME): $(OBJDIR) $(FT_LIB) $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
