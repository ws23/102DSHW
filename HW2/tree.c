#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
	char label;
	int value;
}node;

node *tree;
int num, Min;
char *tmp, *MinPath;

void Create(int size){
	tree = (node*)malloc(sizeof(node)*size);
	tmp = (char*)malloc(sizeof(char)*size);
	MinPath = (char*)malloc(sizeof(char)*size);
	num = 0;
	Min = 150;
}

void Insert(char label, int value){
	tree[num].label = label;
	tree[num].value = value;
	num++;
}


void Search(int index, int z, int count){
	tmp[z] = tree[index].label;
	count += tree[index].value;
	if(index*2+1>num){
		printf("%s=%d\n", tmp, count);
		strcpy(MinPath, (count<Min)?tmp:MinPath);
		Min = (count<Min)?count:Min;
		tmp[z] = 0;
	}
	else{
		Search(2*index+1, z+1, count);	
		if(2*index+2<num)
			Search(2*index+2, z+1, count);
		else if(index*2+2==num){
			printf("%s=%d\n", tmp, count);
			strcpy(MinPath, (count<Min)?tmp:MinPath);
			Min = (count<Min)?count:Min;
			tmp[z] = 0;
		}
	}
	if(index==0)
		printf("%s is shortest path\n", MinPath);
}
