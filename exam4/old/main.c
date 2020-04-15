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

int error2(char *s1, char *s2, int a) {
	write(2, s1, ft_strlen(s1));
	if (s2)
		write(2, s2, ft_strlen(s2));
	write(2, "\n", 1);
	return(a);
}

void exitFatal() {
	exit(error2("error: fatal", NULL, 1));
}

void *secureMalloc(size_t n){
	void *p = malloc(n);
	if(!p)
		exitFatal();
	return p;
}

int cd(char **cmd){
	if (cmd[1] && !cmd[2]){
		if (chdir(cmd[1]))
			return error2("error: cd: cannot change directory to ", cmd[1], 1);
		else
			return 0;
	}
	else
		return error2("error: cd: bad arguments", NULL, 1);
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
		if(pipe(fd) < 0)
			exitFatal();
		pid = fork();
		if(pid < 0)
			exitFatal();
		else if (pid == 0) {
			if (dup2(in, 0) < 0)
				exitFatal();
			if (cmd->next != NULL){
				if (dup2(fd[1], 1) < 0)
					exitFatal();
			}
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
	Elt *e = secureMalloc(sizeof(Elt));
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

		cmd = secureMalloc((j+1)*sizeof(char*));
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
