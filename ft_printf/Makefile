# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 21:41:01 by nicolas           #+#    #+#              #
#    Updated: 2019/10/25 13:40:02 by nklarsfe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GITHUBNAME	= https://github.com/nicokla/1_2_printf.git
GIT42NAME	= vogsphere@vogsphere.42.fr:intra/2019/activities/42cursus_ft_printf/nklarsfe3

NAME	= libftprintf.a
#a.out

SRC		=	parse.c print_int.c \
			print_string.c ft_printf.c utils.c
SRC_BONUS	=	parse_bonus.c print_int_bonus.c \
			print_string_bonus.c ft_printf_bonus.c utils_bonus.c
OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))
OBJ_BONUS	= $(addprefix $(OBJDIR),$(SRC_BONUS:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

FT		= ./libft/
FT_SRC = $(wildcard $(FT)*.c)
FT_LIB	= $(addprefix $(FT),libft.a)
FT_OBJ = $(patsubst %.c, %.o, $(FT_SRC))
FT_INC	= -I./libft
FT_LNK	= -L ./libft -l ft -l pthread

SRCDIR	= ./
INCDIR	= ./includes
OBJDIR	= ./
LIBDIR	= ./
INCLUDES = -I$(FT) -I$(INCDIR)

all: $(FT_LIB) $(NAME)
#$(CREATE) $(FT_LIB) $(NAME)

#$(CREATE):
#	mkdir -p $(OBJDIR)

# $(OBJDIR)%.o:$(SRCDIR)%.c
# 	$(CC) $(CFLAGS) $(FT_INC) -I$(INCDIR) -o $@ -c $<

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_LIB):
	make -C $(FT)

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) $(FT_LNK) -lm -o $(NAME)
$(NAME): $(OBJ)
	ar rc $(LIBDIR)/$(NAME) $(OBJ) $(FT_OBJ)
	ranlib $(LIBDIR)/$(NAME)

bonus: $(FT_LIB) $(OBJ_BONUS)
	ar rc $(LIBDIR)/$(NAME) $(OBJ_BONUS) $(FT_OBJ)
	ranlib $(LIBDIR)/$(NAME)

clean:
	rm -f $(OBJ) $(FT_OBJ)
#make -C $(FT) clean
#rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

test:
	gcc .test.c -g -L$(LIBDIR) -lftprintf $(INCLUDES) -o test

test2:
	gcc .test2.c -g -L$(LIBDIR) -lftprintf $(INCLUDES) -o test2

test3:
	gcc .test3.c -g -L$(LIBDIR) -lftprintf $(INCLUDES) -o test3

testclean: fclean
	rm .test

retest: testclean test


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

retry:
	git remote rm origin
	git remote add origin $(GITHUBNAME)
	git remote set-url --add --push origin $(GITHUBNAME)
	git remote set-url --add --push origin $(GIT42NAME)
	git remote show origin
	git push origin master

failed:
	git remote set-url --delete --push origin $(GIT42NAME)
	git remote show origin

normi:
	norminette *.c *.h */*.c */*.h
	
malloc:
	grep -r 'malloc' -A 3 *.c
