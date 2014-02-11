#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

typedef struct _node{
	char value[1000];
	struct _node *next;
}node;

node table[256], *cur;

void Ini(){
	int i;
	for(i=0;i<256;i++){
		table[i].next = NULL;
		table[i].value[0] = 0;
	}
}

int hashFunc(char *s){
	int ln, i, total = 0;
	ln = strlen(s);
	for(i=0;i<ln;i++){
		if('a'<=s[i] && s[i]<='z')
			total += s[i];
		if('A'<=s[i] && s[i]<='Z')
			total += s[i];
	}
	total = total*total;
	int m[32] = {0};
	int a, b;
	b = total;
	for(i=0;i<32;i++){
		a = b%2;
		b = b/2;
		m[i] = a;
	}
	int z1[8], z2[8], z3[8], z4[8];
	int h = 0, j = 7, k = 0, l = 7;
	for(i=0;i<32;i++){
		if(0<=i && i<=7){
			z2[j] = m[i];
			j--;
		}
		else if(8<=i && i<=15){
			z1[h] = m[i];
			h++;
		}
		else if(16<=i && i<=23){
			z4[l] = m[i];
			l--;
		}
		else if(24<=i && i<=31){
			z3[k] = m[i];
			k++;
		}
	}
	int z[8];
	for(i=0;i<8;i++){
		z[i] = z1[i]+z2[i]+z3[i]+z4[i];
		if(z[i]%2==0) 
			z[i] = 0;
		else 
			z[i] = 1;
	}
	int ans = 0, q = 1;
	for(i=0;i<8;i++){
		ans += z[i]*q;
		q *= 2;
	}
	return ans;
}

node* createNode(char *str){
	node *tmp = (node*)malloc(sizeof(node));
	strcpy(tmp->value, str);
	tmp->next = NULL;
	cur->next = tmp;
	cur = tmp;
	return tmp;
}

node* findTail(node *tbl){
	node *tmp = tbl;
	while(tmp->next)
		tmp = tmp->next;
	return tmp;
}

void Insert(char *str){
	int index = hashFunc(str);
	node *tmp;
	cur = findTail(&table[index]);
	tmp = createNode(str);
}

void Delete(char *str){
	int index = findExist(str);	
	node *tmp;
	if(index==-1)
		printf("%s is not exist in the hash table.\n", str);
	else{
		tmp = &table[index];
		while(tmp){
			if(strcmp(tmp->next->value, str)==0)
				break;
			tmp = tmp->next;
		}
		tmp->next = tmp->next->next;
	}
}

int findExist(char *str){
	int index = hashFunc(str), exist = -1;
	node *tmp = &table[index];
	while(tmp){
		if(strcmp(tmp->value, str)==0){
			exist = index;
			break;
		}
		tmp = tmp->next;
	}
	return exist;
}

void printIndex(int index){
	node *tmp = &table[index];
	while(tmp->next){
		tmp = tmp->next;
		printf("%s ", tmp->value);
	}
	printf("\n");
}

void Print(char *str){
	int index = findExist(str);
	if(index==-1)
		printf("Null\n");
	else
		printIndex(index);
}

void Show(){
	int i;
	node *tmp;
	for(i=0;i<256;i++){
		printf("table[%3d]: ", i);
		tmp = &table[i];
		while(tmp->next){
			tmp = tmp->next;
			printf("%s ", tmp->value);
		}
		printf("\n");
	}
}
