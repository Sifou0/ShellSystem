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
#include <sys/stat.h>
#include <fcntl.h>
void cd(char* path)
{
  int d = chdir(path);
  printf("%d\n",d);
}

int main()
{
    char* s = "bash < test.txt";
    char* start = (char*) malloc(strlen(s) * sizeof(char));
    char* delim = "<";
    int in = 0;
    int out = 0;
    while(*s)
    {
      start[strlen(start)] = *s;
      if(*s == '<')
      {
        in = 1;
        break;
      }
      s++;
    }
    start[strlen(start)- 1 ] = '\0';
    if(start[strlen(start)- 1 ] == ' ') start[strlen(start)- 1 ] = '\0';
    if(in) s++;
    if(s[0] == ' ') s++;
    if(s[0] > 40 && s[0] < 127)
    {
      int opened_file = open(s,0,O_RDONLY);
      if(opened_file)
      {
        char buf[4096];
        read(opened_file,buf,sizeof(buf));
        printf("%s\n",buf);
      }
      close(opened_file);
    }
    else printf("fffff\n");
    printf("%s\n",start);
	return 0;
}