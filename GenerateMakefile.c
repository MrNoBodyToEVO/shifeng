#include "RecognizeFile.h"
#include "GenerateMakefile.h"
int DivideFile(char** filePaths,int pos,char** HFile,char** CFile,int* hpos,int* cpos){
	
	for(int i=0;i<pos;i++){
		if(RecognizeFile(filePaths[i])==IS_H){
			HFile[*hpos]=filePaths[i];
			*hpos=*hpos+1;
		}else if(RecognizeFile(filePaths[i])==IS_C){
			CFile[*cpos]=filePaths[i];
			*cpos=*cpos+1;
		}else{

		}
	}
	return 0;
}

int GenerateLines(char** CFile,char** HFile,int cpos,int hpos,char** result){
	//第一行数据
	char* pre=malloc(6);
	strcpy(pre,"obj =");
	char* cur=NULL;

	//第二行数据
	char* s2_0="app:$(obj)\n	gcc -o app $(obj)\n$(obj):";
	//第三至N的数据
	char* s3=NULL;
	char* s4=NULL;
	//第N+1行数据
	char* sn="clean:\n	rm app $(obj)";
	for(int i=0;i<cpos;i++)
	{
		int lpre=strlen(pre),lcf=strlen(CFile[i]);
		cur=malloc(lpre+lcf+2);
		char* OFile=malloc(lcf+1);
		strcpy(OFile,CFile[i]);
		OFile[lcf-2]='.';
		OFile[lcf-1]='o';
		OFile[lcf]='\0';
		sprintf(cur,"%s %s",pre,OFile);
		//第三至N的数据
		int ls3=0;
		if(s3!=NULL){
			ls3=strlen(s3);
		}
		s4=malloc(lcf*2+3+ls3);
		sprintf(s4,"%s:%s\n",OFile,CFile[i]);
		if(s3!=NULL){
			strcat(s4,s3);
		}
		free(s3);
		s3=s4;
		free(OFile);
		free(pre);
		pre=cur;
	}
	char* s2=NULL;
	char* s2_1="";
	for(int i=0;i<hpos;i++){
		s2=malloc(strlen(HFile[i])+strlen(s2_1)+2);
		sprintf(s2,"%s %s",s2_1,HFile[i]);
		if(s2_1!="")
			free(s2_1);
		s2_1=s2;
	}
	s2=malloc(strlen(s2_1)+strlen(s2_0)+2);
	sprintf(s2,"%s%s\n",s2_0,s2_1);
	char* s1=malloc(strlen(cur)+2);
	sprintf(s1,"%s\n",cur);
	free(cur);
	result[0]=s1;
	result[1]=s2;
	result[2]=s4;
	result[3]=sn;
	return 0;
}
int WriteToMakeFile(char* fileName,char** Lines,int len){
	FILE* f=fopen(fileName,"w");
	for(int i=0;i<len;i++){
		fwrite(Lines[i],1,strlen(Lines[i]),f);
	}
	fclose(f);
}
int GenerateMakefile(char** filePaths,int pos){
	char* HFile[MAX_FILE_COUNT]={};
	char* CFile[MAX_FILE_COUNT]={};
	int hpos=0,cpos=0;
	DivideFile(filePaths,pos,HFile,CFile,&hpos,&cpos);
	printf("HFILE:\n");
	for(int i=0;i<hpos;i++){
		printf("%s\n",HFile[i]);
	}
	printf("CFILE:\n");
	for(int i=0;i<cpos;i++){
		printf("%s\n",CFile[i]);
	}
	char* Lines[4]={};
	GenerateLines(CFile,HFile,cpos,hpos,Lines);
	WriteToMakeFile("Makefile",Lines,4);
}
