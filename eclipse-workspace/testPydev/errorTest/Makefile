obj = ./RecognizeFile.o ./ReadFileList.o ./GenerateMakefile.o ./main.o
app:$(obj)
	gcc -o app $(obj)
$(obj): ./ReadFileList.h ./RecognizeFile.h ./GenerateMakefile.h
./main.o:./main.c
./GenerateMakefile.o:./GenerateMakefile.c
./ReadFileList.o:./ReadFileList.c
./RecognizeFile.o:./RecognizeFile.c
clean:
	rm app $(obj)
