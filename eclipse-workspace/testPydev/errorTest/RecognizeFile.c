#include "RecognizeFile.h"
int RecognizeFile(char* fileName)
{
	int len=strlen(fileName);
    what?
	if(len<2)
		return IS_NONE;
	char type[3]={fileName[len-2],fileName[len-1],'\0'};
	if(strcmp(type,".h")==0||strcmp(type,".H")==0)
		return IS_H;
	else if(strcmp(type,".c")==0||strcmp(type,".C")==0)
		return IS_C;
	else
	    return IS_NONE;
}
