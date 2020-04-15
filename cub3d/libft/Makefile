GITHUBNAME	= https://github.com/nicokla/libft_git.git
GIT42NAME	= vogsphere@vogsphere.42.fr:intra/2019/activities/42cursus_libft/nklarsfe

SRCS		= ft_abs.c ft_atoi.c ft_atoi_base.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memccpy.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_split.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
ft_strjoin.c ft_strjoin2.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
ft_strncpy.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strtrim.c ft_substr.c ft_tolower.c \
ft_toupper.c get_next_line.c get_next_line_utils.c
#  $(shell ls | grep -E "ft_.+\.c")

INC_DIR		= .

OBJS		= $(SRCS:.c=.o)

NAME	= libft.a

CC		= gcc
RM		= rm -f

CFLAGS	= -g -Wall -Wextra -Werror -I$(INC_DIR)

all:		$(NAME)

%.o:%.c
			$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
