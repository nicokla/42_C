#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_IN 2048
#define MAX_PATH 2048
#define CD "cd"

struct argument
{
	char* arg;
	struct argument* next;
};

struct command
{
	char* cmd;
	struct argument* args;
	struct command* next;
	char * in;
	char * out;
};


struct command* tokenizer(char* command_str)
{
	if (command_str==NULL || strlen(command_str)==0)
	{
		return NULL;
	}

	char* token = NULL;

	struct command* tail = NULL;
	struct command* head = tail = (struct command*)malloc(sizeof(struct command));
	head->in=NULL;
	head->out=NULL;
	head->cmd = strtok(command_str, "|");
	tail->next = NULL;

	while (1)
	{
		token = strtok(NULL, "|");
		if (token == NULL)
		{
			break;
		}
		tail->next = (struct command*)malloc(sizeof(struct command));
		tail->out=NULL;
		tail->in=NULL;
		tail = tail->next;
		tail->cmd = token;

		tail->next = NULL;
	}

	struct command* tmp = NULL;

	for(tmp = head; tmp != NULL; tmp = tmp->next)
	{
		struct argument * tailArgs = NULL;
		struct argument * headArgs = tailArgs = (struct argument*)malloc(sizeof(struct argument));
		headArgs->arg = strtok(tmp->cmd, " ");
		tailArgs->next = NULL;

		while (1)
		{
			token = strtok(NULL, " ");
			if (token == NULL)
			{
				break;
			}
			tailArgs->next = (struct argument*)malloc(sizeof(struct argument));
			tailArgs = tailArgs->next;
			tailArgs->arg = token;
			tailArgs->next = NULL;
		}
		tmp->args = headArgs->next;
	}

	return head;
}

int validate_and_replace(struct command* comands)//$agr = env
{
	if (comands == NULL || comands->cmd == NULL)
	{
		return 1;
	}
	else if (strcmp(comands->cmd, CD) == 0)
	{
		if (comands->next != NULL)
		{
			return -1;
		}
		if (comands->args == NULL)
		{
			return -2;
		}
		if (comands->args->next != NULL)
		{
			return -3;
		}
		if (comands->args->arg[0] == '<' || comands->args->arg[0] == '>')
		{
			return -4;
		}
		if (comands->args->arg[0] == '$')
		{
			if (strlen(comands->args->arg) == 1)
			{
				return -5;
			}
			comands->args->arg = getenv(&comands->args->arg[1]);
		}
	}
	else
	{
		struct command* tmp = NULL;
		struct command* firstCmd = comands;

		for (tmp = comands; tmp != NULL; tmp = tmp->next)
		{
			if (comands->cmd == NULL)
			{
				return 1;
			}
			else if (strcmp(tmp->cmd, CD) == 0)
			{
				return -6;
			}
			else
			{
				struct argument* argTmp = NULL;
				for (argTmp = tmp->args; argTmp != NULL; argTmp = argTmp->next)
				{
					if (argTmp->arg[0] == '$')
					{
						if (strlen(argTmp->arg) == 1)
						{
							return -5;
						}
						argTmp->arg[0] = getenv(&argTmp->arg[1]);
					}
					else if(argTmp->arg[0] == '<' && firstCmd == tmp && strlen(argTmp->arg)>=2)
					{
						tmp->in=&argTmp->arg[1];
					}
					else if (argTmp->arg[0] == '>' && tmp->next == NULL && strlen(argTmp->arg)>=2)
					{
						tmp->out=&argTmp->arg[1];
					}
					else if (argTmp->arg[0] == '<' && firstCmd != tmp)
					{
						return -7;
					}
					else if (argTmp->arg[0] == '>' && tmp->next != NULL)
					{
						return -8;
					}
				}
			}
		}
	}
	return 0;
}

void cd(char* curPath, char* newPath)
{
	if (newPath[0] != '/')
	{
		strcat(curPath, "/");
		strcat(curPath, newPath);
		chdir(newPath);
	}
	else
	{
		chdir(&newPath[1]);
	}
}

char ** get_args_cmd(struct command * comand)
{
	int count = 2;
	struct argument * tmp = NULL;
	for(tmp= comand->args; tmp != NULL ; tmp = tmp->next)
	{
		count++;
	}
	char ** args = (char*)malloc(sizeof(char*)*count);
	int i=1;
	for(tmp = comand->args; tmp != NULL ; tmp = tmp->next)
	{
		if(tmp->arg!=NULL && tmp->arg[0]!='<' && tmp->arg[0]!='>')
		{
			args[i]=tmp->arg;
			i++;
		}
	}
	args[0]=comand->cmd;
	args[i]=NULL;
	return args;
}

void exect(struct command* comands)
{
	if(comands==NULL)
	{
		return;
	}
	int fd[2];
	pid_t pid;
	struct command* cmd = NULL;
	int in=0;
	if(comands->in!=NULL)
	{
		in = open(comands->in,O_RDONLY, S_IRUSR);
		//printf("%s",in);
	}
	for(cmd = comands; cmd!=NULL; cmd=cmd->next)
	{
		pipe(fd);
		pid = fork();
		if(pid < 0)
		{
			exit(1);
		}
		else if(pid==0)
		{
			dup2(in,0);
			close(in);
			if(cmd->next != NULL)
			{
				dup2(fd[1],1);
			}
			else if(cmd->out!=NULL)
			{
				int f = open(cmd->out,O_RDWR|O_CREAT,S_IRWXU);
				dup2(f,1);
			}
			char ** args =  get_args_cmd(cmd);
			execvp(cmd->cmd, args);
			free(args);
			close(fd[0]);
			close(fd[1]);
			exit(0);
		}
		else
		{
			wait(NULL);
			close(fd[1]);
			in=fd[0];
		}
	}
	close(fd[1]);
	close(fd[0]);
}

int main()
{
	char user_input[MAX_IN];
	char path[MAX_PATH];

	while (1)
	{
		memset(path, 0, MAX_PATH);
		getcwd(path, MAX_PATH);
		printf("%s$", path);
		memset(user_input, 0, MAX_IN);
		fgets(user_input, MAX_IN, stdin);
		user_input[strlen(user_input) - 1] = 0;

		struct command* comands = tokenizer(user_input);

		if (comands != NULL)
		{
			if (!validate_and_replace(comands))
			{
				if (strcmp(comands->cmd, CD) == 0)
				{
					cd(path, comands->args->arg);
				}
				else
				{
					exect(comands);
				}
			}
		}
	}

	return 0;
}
