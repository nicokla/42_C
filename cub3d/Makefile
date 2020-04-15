# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 21:41:01 by nicolas           #+#    #+#              #
#    Updated: 2019/11/05 18:09:42 by nklarsfe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GITHUBNAME	= https://github.com/nicokla/cub3d.git
GIT42NAME	= vogsphere@vogsphere.42.fr:intra/2019/activities/cub3d/nklarsfe2

NAME	= cub3d

SRC		= main.c parse.c parse2.c error.c utils1.c move.c \
			init.c hooks.c ray.c draw.c free.c libattopng.c \
			libattopng2.c libattopng3.c libattopng4.c libattopng5.c \
			libattopng6.c libattopng7.c
OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Ofast
# -Ofast

FT		= ./libft/
FT_SRC = $(wildcard $(FT)*.c)
FT_LIB	= $(addprefix $(FT),libft.a)
FT_OBJ = $(patsubst %.c, %.o, $(FT_SRC))
FT_INC	= -I./libft
FT_LNK	= -L ./libft -l ft -l pthread

MLX		= ./mlx_mac/
MLX_SRC = $(wildcard $(MLX)*.c)
MLX_LIB	= $(addprefix $(MLX),libmlx.a)
MLX_OBJ = $(patsubst %.c, %.o, $(MLX_SRC))
MLX_INC = -I $(MLX)
MLX_LNK = -L $(MLX) -l mlx -framework OpenGL -framework AppKit

SRCDIR	= ./srcs
INCDIR	= ./includes
OBJDIR	= ./objs
LIBDIR	= ./
INCLUDES = -I$(FT) -I$(MLX) -I$(INCDIR) 

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_LIB):
	make -C $(FT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) $(MLX_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

init:
	git remote add origin https://github.com/nicokla/42_empty_project.git
	git pull origin master
	git remote rm origin
	git remote add origin $(GITHUBNAME)
	git push -u origin master
	git remote set-url --add --push origin $(GITHUBNAME)

commit:
	git add -A
	git commit -m "essai"

push: commit
	git push origin master

newtry:
	git remote rm origin
	git remote add origin $(GITHUBNAME)
	git remote set-url --add --push origin $(GITHUBNAME)
	git remote set-url --add --push origin $(GIT42NAME)
	git remote show origin
	git push origin master

malloc:
	grep -r 'malloc' -A 3 libft/*.c

