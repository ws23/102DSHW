#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "hashfuncs.h"
#define MAX 7439

node *head[MAX] = {NULL};
int collision, num_word, used, max_len;

node* createHead(char *s, int key){
	head[key] = (node*)malloc(sizeof(node));
	head[key]->next = NULL;
	strcpy(head[key]->s, s);
	return head[key];
}

node* createNode(char *s){
	node *tmp = (node*)malloc(sizeof(node));
	tmp->next = NULL;
	strcpy(tmp->s, s);
	return tmp;
}

void Insert(char *s){
	int key, len = 0;
	node *tmp;
	key = hashStringBUZ(s) % MAX;
	if(head[key]==NULL){
		used++;
		len++;
		createHead(s, key);
	}
	else{
		tmp = head[key];
		collision++;
		while(tmp->next!=NULL){
			len++;
			tmp = tmp->next;
			if(tmp->next!=NULL)
				collision++;
		}
		len++;
		max_len = max_len>len?max_len:len;
		tmp->next = createNode(s);
	}
}

void ini(){
	FILE *fin;
	char s[30];
	collision = num_word = used = max_len = 0;
//	fin = fopen("simple.dict", "r");
	fin = fopen("ispell.words", "r");	
	while(fscanf(fin, "%s", s)!=EOF){
		num_word++;
		Insert(s);
	}
}

void showInfo(){
	printf("collision: %d\tdictionarywords: %d\tused: %d\n", collision, num_word, used);
}

int isExist(char *s){
	int exist = 0;
	node *tmp;
	tmp = head[(hashStringBUZ(s)%MAX)];
	while(tmp!=NULL){
		if(strcmp(tmp->s, s)==0){
			exist = 1;
			break;
		}
		tmp = tmp->next;
	}
	return exist;
}

void search(char *s){
	int len, i, j;
	char nS[30];
	len = strlen(s);
	for(i=0;i<len;i++)
		if(s[i]>='A'&&s[i]<='Z')
			s[i] += 'a' - 'A';
	if(!isExist(s)){
		printf("%s:", s);
		for(i=0;i<len;i++){
			strcpy(nS, s);
			for(j=0;j<26;j++){
				nS[i] = j+'a';
				if(isExist(nS))
					printf(" %s", nS);
			}
		}
		printf("\n");
	}
/*	else
		printf("%s is Exist!!\n");*/
}
