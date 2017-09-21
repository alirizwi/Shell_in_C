#include "header.h"
#include "functions.h"

void handler(int sig)
{
	pid_t pid;

	pid = wait(NULL);
	if(pid>0)
		fprintf(stderr,"Pid %d exited.\n", pid);
	//printf("Pid %d exited.\n", pid);
}

void execute(char** args){
	pid_t childpid,wait_pid;
	int status,flag=0;

	signal(SIGCHLD, handler);
	childpid = fork();
	if(childpid < 0){
		fprintf(stderr, "Error: cannot create process\n");
	}
	else if(childpid == 0){
		int i=0;
		while(args[i]){
			if(!strcmp(args[i],"&")){
				flag=1;
				//printf("%d\n",childpid);
				args[i] = NULL;
				break;
			}
			i++;
		}
		if(execvp(args[0],args)<0){
			fprintf(stderr, "Error: cannot execute process\n");
		}
	}
	else
	{
		int i=0;
		while(args[i]){
			if(!strcmp(args[i],"&")){
				flag=1;
				printf("%d\n",childpid);
				args[i] = NULL;
			}
			i++;
		}
		if(flag==0){
			wait_pid = waitpid(childpid,&status,0);
		}
	}
	return;
}
