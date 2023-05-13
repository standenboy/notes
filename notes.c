#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>

#include "config.h" 

void syntaxError(){	
	printf("invalid syntax, use --set --delete --list (-s -d -l)\n");
	exit(1);
}

void Set(char name[]){
	FILE *fptr;
	char dir[] = DIRC;

	struct stat st = {0};
	
	if (stat(dir, &st) == -1) {
		    mkdir(dir, 0700);
	}

	strcat(dir, name);
	fptr = fopen(dir, "w");
	
	if (fptr == NULL){
		printf("failed to open file %s\n",dir);
	       	exit(2);
	}

	char info[200];
	char date[15];
	printf("about this note: ");
	scanf("%199[^\n]", info);
	
	printf("date due: ");
	scanf("%s",date);

	fprintf(fptr, "%s\n%s\n", date, info);

	fclose(fptr);
}

void Delete(char name[]){
	char dir[] = DIRC;
	strcat(dir, name);

	int ret = remove(dir);
	if (ret != 0){
		printf("failed to delete file %s\n",dir);
		exit(3);
	}	
}

void Read(char name[]){

	FILE *fptr;
	char dir[] = DIRC;

	strcat(dir, name);
	fptr = fopen(dir, "r");
	
	if (fptr == NULL){
		printf("failed to open file %s%s\n",dir,name);
	       	exit(2);
	}

	char c;       
	while((c=fgetc(fptr))!=EOF){
		printf("%c",c);
	} 
	fclose(fptr);
	exit(0);

}

void List(){
	DIR *d;
	struct dirent *dir;
	d = opendir(DIRC);
	if (d){
		while ((dir = readdir(d)) != NULL){
	 		printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
}


int main(int argc, char *argv[]){
	if (argc <= 1){
		syntaxError();
	}
	if (!strcmp(argv[1], "-s") || !strcmp(argv[1],"--set")){
		if (argc >= 3){
			Set(argv[2]);
		}
		else{
			syntaxError();
		}
			
	}
	else if (!strcmp(argv[1], "-d") || !strcmp(argv[1],"--delete")){
		if (argc >= 3){
			Delete(argv[2]);
		}
		else{
			syntaxError();
		}
	}
	
	else if (!strcmp(argv[1], "-r") || !strcmp(argv[1],"--read")){
		if (argc >= 3){
			Read(argv[2]);
		}
		else{
			syntaxError();
		}
	}
	else if (!strcmp(argv[1], "-l") || !strcmp(argv[1],"--list")){
		List();
	}
	else{
		syntaxError();
	}
	
	return 0;

}


