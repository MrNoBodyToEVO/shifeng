#include "ReadFileList.h"
int ReadFileList(char *basePath,char** filePaths,int* pos)
{
    DIR *dir;
    struct dirent *ptr;
    char base[1000];

    if ((dir=opendir(basePath)) == NULL)
    {
        perror("Open dir error...");
        exit(1);
    }

    while ((ptr=readdir(dir)) != NULL)
    {
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
            continue;
        else if(ptr->d_type == 8)    ///file
		{
			char* filePath=malloc(strlen(basePath)+strlen(ptr->d_name)+2);
			//printf("%s/%s\n",basePath,ptr->d_name);
            sprintf(filePath,"%s/%s",basePath,ptr->d_name);
			filePaths[*pos]=filePath;
			*pos=*pos+1;
		}
		else if(ptr->d_type == 10)    ///link file
            continue;
        else if(ptr->d_type == 4)    ///dir
        {
            memset(base,'\0',sizeof(base));
            strcpy(base,basePath);
            strcat(base,"/");
            strcat(base,ptr->d_name);
            ReadFileList(base,filePaths,pos);
        }
    }
    closedir(dir);
    return 1;
}
