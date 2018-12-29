#define MAX_FILENAME_LEN 100
#include <stdio.h>
#include "ReadFileList.h"
#include "RecognizeFile.h"
#include "GenerateMakefile.h"
int main(int argc,char** argv)
{
	char* filePaths[MAX_FILE_COUNT]={};
	int pos=0;
	char path[MAX_FILENAME_LEN]=".";
	if(argc>=2){
		strcpy(path,argv[1]);
	}
	
    ReadFileList(path,filePaths,&pos);
	printf("pos=%d\n",pos);
	GenerateMakefile(filePaths,pos);
	printf("END\n");
    return 0;
}
