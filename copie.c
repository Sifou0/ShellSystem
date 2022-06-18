#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "copie.h"
void copie_simple(char fsource[], char ftarget[])
{
    char ch[4096];
    struct stat sd_source,sd_target;
    int source = open(fsource, O_RDONLY);
    int n = read(source,ch,128);
    int target = open(ftarget, O_CREAT | O_WRONLY);
    int x = write(target,ch,n);
    stat(fsource,&sd_source);
    chmod(ftarget,sd_source.st_mode);
    close(source);
    close(target);
}

void copie_directory(char dsource[], char dtarget[])
{
    DIR *source = opendir(dsource);
    struct dirent *rsource = NULL;
    
    while((rsource = readdir(source))!= NULL)
    {
        if (strcmp(rsource -> d_name, ".") != 0 && strcmp(rsource -> d_name, "..") != 0)
        {
            char * sourcePath = malloc(strlen(dsource) + strlen(rsource->d_name) + 1);
            char * destPath = malloc(strlen(dtarget) + strlen(rsource->d_name) + 1);
            strcpy(sourcePath, dsource);
            strcpy(destPath, dtarget);
            if (sourcePath[strlen(sourcePath) - 1] != '/')
                strcat(sourcePath, "/");
            if (destPath[strlen(destPath) - 1] != '/')
                strcat(destPath, "/");
            strcat(sourcePath, rsource->d_name);
            strcat(destPath, rsource->d_name);
            copie_simple(sourcePath,destPath);
        }
    }
    closedir(source);
}

void copie(char fsource[], char ftarget[])
{
    struct stat sd_source;
    stat(fsource,&sd_source);
    if(S_ISDIR(sd_source.st_mode))
    {
        DIR* source = opendir(fsource);
        struct dirent *rsource = NULL;
        while((rsource = readdir(source))!= NULL)
        {
            //printf("%s\n",rsource->d_name);
            if (strcmp(rsource -> d_name, ".") != 0 && strcmp(rsource -> d_name, "..") != 0)
            {
                char* sourcePath = (char*) malloc(strlen(fsource) + strlen(rsource->d_name) + 1);
                char* destPath = (char*) malloc(strlen(ftarget) + strlen(rsource->d_name) + 1);
                strcpy(sourcePath,fsource);
                strcpy(destPath,ftarget);
                if (sourcePath[strlen(sourcePath) - 1] != '/')
                    strcat(sourcePath, "/");
                if (destPath[strlen(destPath) - 1] != '/')
                    strcat(destPath, "/");
                strcat(sourcePath,rsource -> d_name);
                strcat(destPath,rsource -> d_name);
                if(rsource->d_type == DT_DIR)
                {
                    mkdir(destPath,S_IRWXU);
                    copie(sourcePath,destPath);
                }
                else
                {
                    copie_simple(sourcePath,destPath);
                }
            }
        }
        closedir(source);
    }
    else
    {
        copie_simple(fsource,ftarget);
    }
    
    
}

