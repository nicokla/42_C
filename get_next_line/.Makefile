GITHUBNAME	= https://github.com/nicokla/1_3_get_next_line.git
GIT42NAME	= vogsphere@vogsphere.42.fr:intra/2019/activities/42cursus_get_next_line/nklarsfe4

SRC =  get_next_line.c get_next_line_utils.c
OBJ = get_next_line.o get_next_line_utils.o
BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_OBJ = get_next_line_bonus.o get_next_line_utils_bonus.o

all:
	gcc -g -D BUFFER_SIZE=32 -c $(SRC)

bonus:
	gcc -g -D BUFFER_SIZE=32 -c $(BONUS_SRC)

test:	all
		gcc -g -c .test.c
		gcc $(OBJ) .test.o -o test
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
