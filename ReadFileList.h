#ifndef _READFILELIST_H
#define _READFILELIST_H
#include <dirent.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ReadFileList(char* basePath,char** filePaths,int* pos);
#endif
