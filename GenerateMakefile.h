#ifndef _GENERATEMAKEFILE_H
#define _GENERATEMAKEFILE_H
#define MAX_FILE_COUNT 100
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int DivideFile(char** filePaths,int pos,char** HFile,char** CFile,int* hpos,int* cpos);
int GenerateLines(char** CFile,char** HFile,int cpos,int hpos,char** result);
int WriteToMakeFile(char* fileName,char** Lines,int len);
int GenerateMakefile(char** filePaths,int pos);
#endif
