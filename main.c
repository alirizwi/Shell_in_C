#include "header.h"
#include "functions.h"

void echo(char** args){
	int i=1;
	while(args[i]!=NULL){
		printf("%s ",args[i]);
		i++;
	}
	printf("\n");
	return;
}
void pwd(){
	char cwd[100];
	getcwd(cwd,100);
	printf("%s\n",cwd);
	return;
}
void cd(char** args){
	if(args[1]){
		if(!chdir(args[1])){
			//printf("cd ho gya\n");
		}
		else{
			fprintf(stderr, "Error: cd: %s: No such file or directory\n",args[1]);
		}
	}
	else
	{
		chdir(getenv("HOME"));
	}
	return;
}

int main(int argc, char const *argv[])
{
	char *input,dirr[100];
	char home[100],cwd[100],host_name[100];
	char promt_dir[100];
	getcwd(home, 100);
	gethostname(host_name, 100);
	while(1){
		getcwd(cwd,100);

		if(!strcmp(cwd,home)){
			strcpy(promt_dir,"~");
		}
		else if(strstr(home, cwd) != NULL){
			//printf("cwd %d\n",strlen(cwd));
			//printf("home %d\n",strlen(home));
			strcpy(promt_dir,cwd);
		}
		else if(strstr(cwd, home) != NULL){
			//printf("case sahi hai\n");
			char p[100]; //= strstr(cwd,home);
			int len = strlen(home);
			int j=0;
			p[0]='~';
			for(j=1;j<strlen(cwd)-strlen(home)+1 ;j++){
				p[j] = cwd[j+strlen(home)-1];	
			}
			p[j]='\0';
			strcpy(promt_dir,p);
		}
		printf("%s@%s:%s>", getlogin(),host_name,promt_dir);
		input = read_line();
		char* inp = strsep(&input,";");
		char** args = split_line(inp);

		if(args[0]){
			if(!strcmp(args[0],"echo")){
				echo(args);
			}
			else if(!strcmp(args[0],"pwd")){
				pwd();
			}
			else if(!strcmp(args[0],"cd")){
				cd(args);
			}
			else if(!strcmp(args[0],"ls")){
				if( !args[1] || (args[1] && strcmp(args[1],"&"))){
					ls(args);
				}else
					execute(args);
			}
			else if(!strcmp(args[0],"exit")){
				exit(0);
			}
			else
				execute(args);
		}
	}
	return 0;
}