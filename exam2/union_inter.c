#include <unistd.h>

void myunion(unsigned char *a, unsigned char *b){
	char found[256] = {0};
	int i = 0;
	while(a[i]){
		if (!found[a[i]])
			write(1,&a[i],1);
		found[a[i]] = 1;
		i++;
	}
	i = 0;
	while(b[i]){
		if (!found[b[i]])
			write(1,&b[i],1);
		found[b[i]] = 1;
		i++;
	}
}

void inter(unsigned char *a, unsigned char *b){
	char found[256] = {0};
	int i = 0;
	while(b[i]){
		found[b[i]] = 1;
		i++;
	}
	i = 0;
	while(a[i]){
		if(found[a[i]] == 1){
			write(1,&a[i],1);
			found[a[i]] = 2;
		}	
		i++;
	}
}

int main(int ac, char **av){
	if(ac == 3)
		inter((unsigned char *)av[1], 
			(unsigned char *)av[2]);
	write(1,"\n",1);
	return 0;
}


