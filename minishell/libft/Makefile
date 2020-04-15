# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 12:02:11 by cyhuet            #+#    #+#              #
#    Updated: 2019/11/20 15:07:49 by nklarsfe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_itoa_base.c ft_pow.c ft_pow_long.c ft_strrev.c ft_get_index.c \
		ft_itoa.c  ft_memcpy.c ft_strnew.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memmove.c \
		ft_memset.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c \
		ft_split.c ft_strcat.c ft_strchr.c ft_strcpy.c \
		ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
		ft_strequ.c ft_toupper.c ft_putendl.c ft_strcmp.c fatal_error.c

SRCS_BONUS =	ft_lstmap.c ft_lstnew.c ft_lstsize.c \
				ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstadd_front.c

OBJECTS = $(SRCS:%.c=%.o)

OBJECTS_BONUS = $(SRCS_BONUS:%.c=%.o)

CC = @gcc

CFLAGS = -Wall -Werror -Wextra -I. -I../includes -c

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all

bonus: $(OBJECTS) $(OBJECTS_BONUS)
	@ar rc $(NAME) $(OBJECTS) $(OBJECTS_BONUS)
	@ranlib $(NAME)
