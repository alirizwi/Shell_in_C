int isDirectory(const char *path);
void handler(int sig);
char* read_line();
char** split_line(char* input);
void ls(char** args);
void execute(char** args);
