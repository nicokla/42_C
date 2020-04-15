// -------------------
// printf

#include <stdio.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...);

int main(){

	ft_printf("%10.2s\n", "toto");
	ft_printf("Magic %s is %5d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf(":%11.9d:\n", -12345);
	ft_printf(":%11.9d:\n", -12345);
	return (0);
}


// -------------------
// gnl

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int		get_next_line(const int fd, char **line);

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