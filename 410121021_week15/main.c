#include <stdio.h>
#include <string.h>
#include "hash.h"

int main(){
	char cmd[7], str[1000];
	Ini();
	while(scanf("%s %s", cmd, str)!=EOF){
		if(strcmp(cmd, "INSERT")==0)
			Insert(str);
		else if(strcmp(cmd, "DELETE")==0)
			Delete(str);
		else if(strcmp(cmd, "PRINT")==0)
			Print(str);
		else if(strcmp(cmd, "SHOW")==0)
			Show();
		else
			printf("Command Error!!\n");
	}	
	return 0;
}
