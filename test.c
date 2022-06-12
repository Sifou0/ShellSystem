#include <sys/types.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>

void cd(char* path)
{
  int d = chdir(path);
  printf("%d\n",d);
}

int main()
{
    char* buf[2];
    buf[0] = "ls";
    buf[1] = NULL; 
    char cwd[100];
    cd("testfff");
    getcwd(cwd,100);
    printf("%s\n",cwd);
	return 0;
}