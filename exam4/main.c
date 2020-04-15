#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define SIDE_OUT 0
#define SIDE_IN 1

#define STDIN 0
#define STDOUT 1

char **env;

typedef struct Elt_{
	char **cmd;
	struct Elt_ *previous;
	struct Elt_ *next;
	int pipes[2];
} Elt;

typedef struct Commands_{
	Elt *first;
	Elt *last;
} Commands;

int ft_strlen(char *s){
	int i = 0;
	while(s[i])
		i++;
	return i;
}

void error(char *s1, char *s2){
	write(2, s1, ft_strlen(s1));
	if(s2)
		write(2, s2, ft_strlen(s2));
	write(2,"\n",1);
}

void fatalError(){
	error("error: fatal", NULL);
	exit(1);
}

void fatalErrorCond(int a){
	if(a)
		fatalError();
}

void addCommand(Commands *commands, char **cmd){
	Elt *e;
	e = malloc(sizeof(Elt));
	fatalErrorCond(e == NULL);
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

int cd(char **cmd){
	if(!(cmd[1] && !cmd[2])){
		error("error: cd: bad arguments", NULL);
		return 1;
	}
	else if (chdir(cmd[1]) != 0){
		error("error: cd: cannot change directory to ", cmd[1]);
		return 1;
	}
	return 0;
}

int executeCommand(Elt *e){
	pid_t pid;
	int ret;
	int status;
	int tmp;

	ret = EXIT_FAILURE;
	if(e->next){
		tmp = pipe(e->pipes);
		fatalErrorCond(tmp < 0);
	}
	pid = fork();
	fatalErrorCond(pid < 0);
	if(pid == 0){
		if (e->previous) {
			tmp = dup2(e->previous->pipes[SIDE_OUT], STDIN);
			fatalErrorCond(tmp < 0);
		}
		if (e->next) {
			tmp = dup2(e->pipes[SIDE_IN], STDOUT);
			fatalErrorCond(tmp < 0);
		}
		ret = execve(e->cmd[0], e->cmd, env);
		if(ret < 0)
			error("error: cannot execute ", e->cmd[0]);
		exit(ret);
	}
	else {
		waitpid(pid, &status, 0);
		if (e->previous){
			tmp = close(e->previous->pipes[SIDE_OUT]);
			fatalErrorCond(tmp < 0);
		}
		if (e->next){
			tmp = close(e->pipes[SIDE_IN]);
			fatalErrorCond(tmp < 0);
		}
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return ret;
}

int executeCommands(Commands *commands){
	Elt *e = commands->first;
	int ret = EXIT_SUCCESS;

	while(e != NULL){
		if(strcmp(e->cmd[0],"cd") == 0)
			ret = cd(e->cmd);
		else
			ret = executeCommand(e);
		e = e->next;
	}
	return ret;
}

int main(int ac, char **av, char **env_){
	env = env_;
	(void)ac;
	int ret = EXIT_SUCCESS;
	int foundPipe = 0, foundSemiCol = 0;
	int i = 1;
	int j, i0, k;
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
		fatalErrorCond(cmd == NULL);
		cmd[j] = NULL;
		for (k = 0; k < j; k++){
			cmd[k] = av[i0 + k];
		}
		addCommand(commands, cmd);

		if(!foundPipe){
			ret = executeCommands(commands);
			freeCommands(commands);
		}
	}
	return ret;
}
