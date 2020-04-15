#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char **envp;

typedef struct Elt_{
	char **cmd;
	struct Elt_ * next;
} Elt;

typedef struct Commands_{
	Elt *begin;
	Elt *end;
} Commands;

int ft_strlen(char *s){
	int i = 0;
	while(s[i])
		i++;
	return i;
}

void ft_memcpy(char *dest, char *src, int n){
	int i;
	for(i = 0; i < n; i++){
		dest[i] = src[i];
	}
}

int error2(char *s1, char *s2, int a) {
	write(2, s1, ft_strlen(s1));
	if (s2)
		write(2, s2, ft_strlen(s2));
	write(2, "\n", 1);
	return(a);
}

char *getPwdEnv(){
	char *s;
	s = malloc(1024 + 5);
	ft_memcpy(s, "PWD=", 4);
	getcwd(s + 4, 1024);
	return (s);
}

int cd(char **cmd){
	int i;
	if (cmd[1] && !cmd[2]){
		if (chdir(cmd[1])){
			return error2("error: cd: cannot change directory to ", cmd[1], 1);
		}
		else {
			i = 0;
			while(strncmp(envp[i], "PWD=", 4) != 0)
				i++;
			envp[i] = getPwdEnv();
			return 0;
		}
	}
	else {
		return error2("error: cd: bad arguments", NULL, 1);
	}
}

int exec(char **cmd){
	int output;
	output = execve(cmd[0], cmd, envp);
	if (output){
		return error2("error: cannot execute ", cmd[0], output);
	}
	return 0;
}

int executeCommands(Commands *commands){
	Elt *first = commands->begin;
	Elt *cmd;
	int fd[2];
	int in = 0;
	pid_t pid;
	int status;
	int output;

	for(cmd = first; cmd!=NULL; cmd=cmd->next) {
		pipe(fd);
		if ((pid = fork()) == 0) {
			dup2(in, 0);
			if (cmd->next != NULL)
				dup2(fd[1], 1);
			close(fd[0]);
			output = exec(cmd->cmd);
			exit(output);
		} else {
			waitpid(pid, &status, 0);
			close(fd[1]);
			in = fd[0];
			if (WEXITSTATUS(status))
				return(WEXITSTATUS(status));
		}
	}
	return 0;
}

void addCommand(Commands *cmds, char **cmd){
	Elt *e = malloc(sizeof(Elt));
	e->cmd = cmd;
	e->next = NULL;
	if(!cmds->end){
		cmds->begin = e;
		cmds->end = e;
	} else {
		cmds->end->next = e;
		cmds->end = e;
	}
}

// ./a.out /bin/echo toto ";" /bin/echo titi
// ./a.out /bin/ls "|" /bin/cat -e "|" /bin/cat -e
// ./a.out cd toto ";" /bin/ls
// ./a.out /bin/mkdir -p truc ";" /usr/bin/touch truc/yo ";" cd truc ";" /bin/ls "|" /bin/cat -e
int main(int ac, char **av, char **envp_){
	(void)ac;
	envp = envp_;
	int i = 1;
	int j = 0;
	int i0;
	int k;
	char **cmd;
	int foundPipe = 0;
	int foundSemiCol = 0;
	Commands cmds_;
	Commands *cmds = &cmds_;
	cmds->begin = NULL;
	cmds->end = NULL;
	int output;

	while(av[i]){
		j = 0;
		i0 = i;

		while(av[i]){
			foundPipe = (strcmp(av[i], "|") == 0);
			foundSemiCol = (strcmp(av[i], ";") == 0);
			if (foundPipe || foundSemiCol){
				i++;
				break;
			}
			++j;
			++i;
		}
		if(j == 0)
			continue;

		cmd = malloc((j+1)*sizeof(char*));
		cmd[j] = NULL;
		for(k = i0; k < (i0+j); k++){
			cmd[k - i0] = av[k];
		}
		addCommand(cmds, cmd);

		if (!foundPipe) {
			if (strcmp(cmd[0], "cd") == 0) {
				output = cd(cmd);
			} else {
				output = executeCommands(cmds);
			}
			cmds->begin = NULL;
			cmds->end = NULL;
		}
	}
	return 0;
}
