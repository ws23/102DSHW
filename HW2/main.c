#include <stdio.h>
#include "tree.h"

int main(){
	char label, c;
	int value;
	Create(10000);
	while(scanf("(%c,%d)%c", &label, &value, &c)!=EOF){
		Insert(label, value);
		if(c!=',')
			break;
	}
	Search(0, 0, 0);	
	return 0;
}
