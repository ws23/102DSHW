#include <stdio.h>
#include "hash.h"

int main(int arc, char *arv[]){
	FILE *fin;
	int i;
	char s[30];
	ini();
	for(i=1;i<arc;i++){
		fin = fopen(arv[i], "r");
		if(fin==NULL){
			printf("%s is not Exist. \n", arv[i]);
			continue;
		}
		printf("In \"%s\":\n", arv[i]);
		while(fscanf(fin, "%s", s)!=EOF)
			search(s);		
		fclose(fin);
		printf("\n");
	}
	showInfo();
	return 0;
}
