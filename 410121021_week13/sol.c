#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct _node{
	int value, weight;
}node;

int n, queue[10000];
node **bit;

void DFS(int q[], int v){
	int i;
	q[v] = 1;
	printf(" %d", v);
	for(i=0;i<n;i++){
		if(q[bit[v][i].value]!=1)
			DFS(q, bit[v][i].value);
	}
}

void BFS(int q[], int v){
	int i, frIndex, bkIndex, size;
	frIndex = bkIndex = 0;
	queue[bkIndex++] = v;
	while(frIndex!=bkIndex){
		if(q[queue[frIndex]]!=1)
			printf(" %d", queue[frIndex]);
		q[queue[frIndex]] = 1;
		for(i=0;i<n;i++){
			if(q[bit[queue[frIndex]][i].value]!=1)
				queue[bkIndex++] = bit[queue[frIndex]][i].value;
		}
		frIndex++;
	}
}

void call(int start){
        int *q, i, c;
	c = pow(2, n);
        q = (int*)malloc(sizeof(int)*n);
 	for(i=0;i<c;i++)
		q[i] = 0;
	printf("dfs start from %d\n", start);
        DFS(q, start);
	printf("\n");
        memset(q, 0 , sizeof(q));
	for(i=0;i<c;i++)
		q[i] = 0;
	printf("bfs start from %d\n", start);
        BFS(q, start);
        printf("\n");
	
}

void show(){
	int i, j, c;
	c = pow(2, n);
	for(i=0;i<c;i++){
		printf("%d: ", i);
		for(j=0;j<n;j++)
			printf("(%d, %d) ", bit[i][j].value, bit[i][j].weight);
		printf("\n");
	}
}

node binToDec(int b[]){
	int i;
	node dec;
	dec.value = dec.weight = 0;
	for(i=0;i<n;i++){
		dec.value += b[i]*(int)pow(2, i);
		dec.weight += (b[i]==1?1:0);
	}
	return dec;
}

void trans(int v){
	int i, j, t, *tmp, *tmp2;
	tmp = (int*)malloc(sizeof(int)*n);
	tmp2 = (int*)malloc(sizeof(int)*n);
	memset(tmp, 0, sizeof(tmp));
	t = v;
	for(i=0;t;i++){
		tmp[i] = t % 2;
		t /= 2;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			tmp2[j] = tmp[j];
		tmp2[i] = (tmp2[i]==1)?0:1;
		bit[v][i] = binToDec(tmp2);
	}
}

void create(int size){
	int i, c;
	c = pow(2, size);
	n = size;
	bit = (node**)malloc(sizeof(node*)*c);
	memset(bit, 0, sizeof(bit));
	for(i=0;i<c;i++){
		bit[i] = (node*)malloc(sizeof(node)*size);
		trans(i);
	}
}
