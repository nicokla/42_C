#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(){
	int fd = open(".fichier1.txt", O_RDONLY);
	int tmp;
	char *line;
	tmp = get_next_line(fd, &line);
	while (tmp != 0){
		printf("%s\n", line);
		free(line);
		line = NULL;
		tmp = get_next_line(fd, &line);
	}
	printf("%s", line);
	free(line);
	line = NULL;
	return 0;
}