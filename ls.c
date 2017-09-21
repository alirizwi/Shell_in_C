#include "header.h"
#include "functions.h"

int isDirectory(const char *path) {
	struct stat statbuf;
	if (stat(path, &statbuf) != 0)
		return 0;
	return S_ISDIR(statbuf.st_mode);
}

void ls(char** args){

	char a[10]=".";
	char b[10]="..";
	DIR *dp;
	struct dirent *dirp;
	struct group *grp;
	struct passwd *pwd;
	int flag=0;
	if(args[1] && isDirectory(args[1])){

		if ((dp = opendir(args[1])) == NULL)
			printf("can’t open %s", "args[1]");
		flag=1;
	}
	else{
		if ((dp = opendir(".")) == NULL)
			printf("can’t open %s", ".");
	}
	while ((dirp = readdir(dp)) != NULL){
		struct stat fileStat;
		stat(dirp->d_name,&fileStat);   
		if(flag){
			if(strcmp(dirp->d_name,a)){
				if(strcmp(dirp->d_name,b)){
					char temp = dirp->d_name[0];
					if(temp!='.'){
						printf("%s",dirp->d_name);

						printf(" ");}}}
			continue;
		}
		if(!args[1]){

			if(strcmp(dirp->d_name,a)){
				if(strcmp(dirp->d_name,b)){
					char temp = dirp->d_name[0];
					if(temp!='.'){
						printf("%s",dirp->d_name);

						printf(" ");}}}

			continue;
		}

		if(!strcmp(args[1],"-a")){
			if(!args[2]){
				printf("%s",dirp->d_name);
				printf(" ");
				continue;
			}
		}

		if(!strcmp(args[1],"-l") || !strcmp(args[1],"-la") || !strcmp(args[1],"-al") || (!strcmp(args[1],"-l") && !strcmp(args[2],"-a")) || (!strcmp(args[1],"-a") && !strcmp(args[2],"-l")))
		{    //printf("File Permissions: \t");
			char temp = dirp->d_name[0];
			if(!strcmp(args[1],"-l") && !args[2]){

				if(strcmp(dirp->d_name,a)){
					if(strcmp(dirp->d_name,b)){
						if(temp!='.'){
							printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
							printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
							printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
							printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
							printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
							printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
							printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
							printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
							printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
							printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
							//printf("");

							printf("\t%d ",(int)fileStat.st_nlink);
							pwd = getpwuid(geteuid());
							printf("\t%s", pwd->pw_name); //username

							grp = getgrgid((fileStat.st_gid));
							printf("\t%s", grp->gr_name); //group name


							printf("\t%d\t",(int)fileStat.st_size);
							char* tim = ctime(&fileStat.st_mtime);
							int i;
							for(i=4;i<strlen(tim)-9;i++)
								printf("%c",tim[i]);
							//printf("\n");
							printf("%d\t",fileStat.st_uid);



							printf("%s",dirp->d_name);




							printf("\n");
							continue;

						}}}
			}
			else{
				printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
				printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
				printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
				printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
				printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
				printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
				printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
				printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
				printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
				printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
				//printf("");

				printf("\t%d ",(int)fileStat.st_nlink);
				pwd = getpwuid(geteuid());
				printf("\t%s", pwd->pw_name); //username

				grp = getgrgid((fileStat.st_gid));
				printf("\t%s", grp->gr_name); //group name


				printf("\t%d\t",(int)fileStat.st_size);
				char* tim = ctime(&fileStat.st_mtime);
				int i;
				for(i=4;i<strlen(tim)-9;i++)
					printf("%c",tim[i]);
				//printf("\n");
				printf("%d\t",fileStat.st_uid);

				printf("%s",dirp->d_name);
				printf(" ");




				printf("\n");
				continue;

			}
		}   } 
	printf("\n");
	return;
}