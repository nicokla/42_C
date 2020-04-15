
int		arr_len(char **arr) {
	int	count;
	count = 0;
	if (!arr)
		return (0);
	while (*arr) {
		count++;
		arr++;
	}
	return (count);
}

void printList(char **l){
	int i = 0;
	while(l[i]){
		printf("%s\n", l[i]);
		i++;
	}
	printf("%c", '\n');
}


void printPwd(char **envp){
	int i = 0;
	while(!isPwd(envp[i]))
		i++;
	printf("%s\n", envp[i]);
}
