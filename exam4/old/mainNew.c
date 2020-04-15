#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIDE_OUT	0
#define SIDE_IN		1

#define STDIN		0
#define STDOUT		1
#define STDERR		2

char **env;

typedef struct Elt_{
	char **cmd;
	struct Elt_ *next;
	struct Elt_ *previous;
	int	pipes[2];
} Elt;

typedef struct Commands_{
	Elt *first;
	Elt *last;
} Commands;

int ft_strlen(char *s){
	int i=0;
	while(s[i])
		i++;
	return i;
}

int error(char *s1, char *s2, int a){
	write(2, s1, ft_strlen(s1));
	if(s2)
		write(2, s2, ft_strlen(s2));
	write(2,"\n",1);
	return a;
}

void fatalError(){
	exit(error("error: fatal", NULL, 1));
}

int cd(char **cmd){
	if(!(cmd[1] && !cmd[2]))
		return error("error: cd: bad arguments", NULL, 1);
	else if(chdir(cmd[1]) != 0)
		return error("error: cd: cannot change directory to ", cmd[1], 1);
	return 0;
}

int exec(char **cmd){
	int output;
	output = execve(cmd[0], cmd, env);
	if(output)
		return error("error: cannot execute ", cmd[0], output);
	return 0;
}

int executeCommands(Commands *commands) {
	Elt *first = commands->first;
	Elt *cmd;
	pid_t	pid;
	int		ret;
	int		status;

	ret = EXIT_FAILURE;
	for(cmd = first; cmd != NULL; cmd = cmd->next){
		if (cmd->next)
			pipe(cmd->pipes);
		pid = fork();
		if (pid == 0) {
			if (cmd->next)
				dup2(cmd->pipes[SIDE_IN], STDOUT);
			if (cmd->previous)
				dup2(cmd->previous->pipes[SIDE_OUT], STDIN);
			ret = exec(cmd->cmd);
			exit(ret);
		}
		else {
			waitpid(pid, &status, 0);
			if (cmd->next)
				close(cmd->pipes[SIDE_IN]);
			if (cmd->previous)
				close(cmd->previous->pipes[SIDE_OUT]);
			if (WIFEXITED(status))
				ret = WEXITSTATUS(status);
		}
	}
	return (ret);
}

void addCommand(Commands *commands, char **cmd){
	Elt *e = malloc(sizeof(Elt));
	e->cmd = cmd;
	e->next = NULL;
	e->previous = NULL;
	if(!commands->last){
		commands->first = e;
		commands->last = e;
	}
	else {
		commands->last->next = e;
		e->previous = commands->last;
		commands->last = e;
	}
}

void freeCommands(Commands *commands){
	Elt *e = commands->first;
	Elt *tmp;
	while(e){
		free(e->cmd);
		tmp = e;
		e = e->next;
		free(tmp);
	}
	commands->first = NULL;
	commands->last = NULL;
}

int main(int ac, char **av, char **env_){
	env = env_;
	(void)ac;
	int i=1, j, i0, k, output, foundPipe=0, foundSemiCol=0;
	char **cmd;
	Commands commands_;
	Commands *commands = &commands_;
	commands->first = NULL;
	commands->last = NULL;

	while(av[i]){
		i0 = i;
		j = 0;
		while(av[i]){
			foundPipe = (strcmp(av[i], "|") == 0);
			foundSemiCol = (strcmp(av[i], ";") == 0);
			if (foundPipe || foundSemiCol){
				i++;
				break;
			}
			i++;
			j++;
		}
		if(j == 0)
			continue;
		
		cmd = malloc(sizeof(char*)*(j+1));
		cmd[j] = NULL;
		for(k = 0; k < j; k++){
			cmd[k] = av[i0 + k];
		}
		addCommand(commands,cmd);

		if(!foundPipe){
			if(strcmp(cmd[0], "cd") == 0)
				output = cd(cmd);
			else
				output = executeCommands(commands);
			freeCommands(commands);
		}
	}
	return 0;
}
