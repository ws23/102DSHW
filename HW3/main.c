#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "depend.h"

char** getDep(char*); // Process the inputed-string

int main(){
	char cmd[100], **dep, tmp[10101];
	int i;

	// Initualization
	dep = (char**)malloc(sizeof(char*)*100);
	for(i=0;i<100;i++)
		dep[i] = (char*)malloc(sizeof(char)*100);
	Ini();


	while(scanf("%s", cmd)!=EOF){
		if(strcmp(cmd, "DEPEND")==0){
			scanf("%s", cmd);
			gets(tmp);
			printf("DEPEND %s%s\n", cmd, tmp);
			memset(dep, 0, sizeof(dep));
			dep = getDep(tmp);
			Create(cmd, dep);
		}
		else if(strcmp(cmd, "INSTALL")==0){
			scanf("%s", cmd);
			printf("INSTALL %s\n", cmd);
			Install(cmd);	
		}
		else if(strcmp(cmd, "REMOVE")==0){
			scanf("%s", cmd);
			printf("REMOVE %s\n", cmd);
			Remove(cmd);
		}
		else if(strcmp(cmd, "LIST")==0){
			printf("LIST\n");
			List();
		}
		else if(strcmp(cmd, "END")==0){
			printf("END\n");	
			break;
		}
		else
			printf("Command Error!!\n");
	}
	return 0;
}

char** getDep(char *str){
	char **tmp, *tok;
	int i, j;
	tmp = (char**)malloc(sizeof(char*)*100);
	for(i=0;i<100;i++)
		tmp[i] = (char*)malloc(sizeof(char)*100);
	i = 0;
	tok = strtok(str, " ");
	do{
		strcpy(tmp[i++], tok);
		tok = strtok(NULL, " ");
	}while(tok);
	return tmp;
}
