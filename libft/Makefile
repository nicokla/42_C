GITHUBNAME	= https://github.com/nicokla/libft_git.git
GIT42NAME	= vogsphere@vogsphere.42.fr:intra/2019/activities/42cursus_libft/nklarsfe4

# SRCS		= $(shell ls | grep -E "ft_.+\.c" | grep -v bonus)
# SRCS_BONUS	= $(shell ls | grep -E "ft_.*_bonus.c")
SRCS_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
ft_lstnew.c ft_lstsize.c
SRCS = ft_abs.c ft_atoi.c ft_atoi_base.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strcat.c ft_strchr.c ft_strcmp.c \
ft_strcpy.c ft_strdup.c ft_strjoin.c ft_strjoin2.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnew.c \
ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strtrim.c \
ft_substr.c ft_tolower.c ft_toupper.c
INC_DIR		= .

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

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

bonus:		$(OBJS) $(OBJS_BONUS)
			rm -f $(NAME)
			ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
			ranlib $(NAME)


clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonusclean:
			$(RM) $(OBJS)
			$(RM) $(OBJS_BONUS)

bonusfclean: bonusclean
			$(RM) $(NAME)

bonusre:	bonusfclean bonus

test: bonusre
	gcc .main.c -g -I. -L. -lft -o test

test2:
	gcc .main.c -g -I. -L. -lft -o test

.PHONY:		all clean fclean re


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
	git add -A
	git commit -m "essai"
	git push origin master

failed:
	git remote set-url --delete --push origin $(GIT42NAME)
	git remote show origin

normi:
	norminette *.c *.h */*.c */*.h

malloc:
	grep -r 'malloc' -A 3 *.c
