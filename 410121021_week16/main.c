#include <stdio.h>
#include <string.h>
#include "dlist.h"

int main(){
	char cmd[3];
	int value;
	while(scanf("%s", cmd)!=EOF){
		if(strcmp(cmd, "IT")==0){
			scanf("%d", &value);
			insertTail(value);
		}
		else if(strcmp(cmd, "IH")==0){
			scanf("%d", &value);
			insertHead(value);
		}
		else if(strcmp(cmd, "S")==0)
			Swap();	
		else if(strcmp(cmd, "RT")==0)
			printf("%d\n", removeTail());
		else if(strcmp(cmd, "RH")==0)
			printf("%d\n", removeHead());
		else
			printf("Command Error. \n");
	}
	return 0;
}
