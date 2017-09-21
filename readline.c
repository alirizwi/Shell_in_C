#include "header.h"
#include "functions.h"

#define line_buffersize 256

char* read_line(){
	int i=0,ch;
	int buffer_size = line_buffersize;
	char* buffer = (char*)malloc(buffer_size * sizeof(char));
	if(!buffer){
		fprintf(stderr, "Error: could not allocate memory\n");
		exit(0);
	}
	while(1){
		
		ch = getchar();
		//check character by character
		if(ch =='\n' || ch == EOF){
			buffer[i] = '\0';
			return buffer;
		}
		else
		{
			buffer[i] = ch;
		}
		i += 1;


		if(i < buffer_size)
			continue;
		else{
			buffer_size += line_buffersize;
			buffer = realloc(buffer,buffer_size);
			if(!buffer){
				fprintf(stderr, "Error: could not allocate memory\n");
				exit(0);
			}	
		}
	}

}
