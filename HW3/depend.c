#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
	char name[100];
	struct _node *next, *dep[100];
	int isInstall, numDep;
}node;

typedef struct _record{
	struct _record *next;
	node *val;
}record;

node *list, *cur;
record *order, *curr;

void Ini(){
	list = (node*)malloc(sizeof(node));
	order = (record*)malloc(sizeof(record));
	cur = list;
	curr = order;
}

node* isExist(char *proName){
	node *tmp = list;
	while(tmp && strcmp(tmp->name, proName))
		tmp = tmp->next;
	return tmp;
}

node* createNode(char *proName){
	node *tmp = (node*)malloc(sizeof(node));
	tmp->next = NULL;
	strcpy(tmp->name, proName);
	tmp->isInstall = 0;
	cur->next = tmp;
	cur = tmp;
	return tmp;
}

void createDep(node *pro, char **dep){
	int i;
	node *tmp;
	for(i=0;dep[i][0];i++){
		tmp = isExist(dep[i]);
		if(!tmp)
			tmp = createNode(dep[i]);
		pro->dep[i] = tmp;
	}
	pro->numDep = i;
}

void Create(char *src, char **dep){
	node *tmp;
	tmp = isExist(src);
	if(!tmp)
		tmp = createNode(src);
	createDep(tmp, dep);
}

void recordOrder(node *pro){
	record *tmp = (record*)malloc(sizeof(record));
	tmp->val = pro;
	tmp->next = NULL;
	curr->next = tmp;
	curr = tmp;
}

void doInstall(node *pro){
	int i;
	if(!pro->isInstall){
		for(i=0;i<pro->numDep;i++)
			doInstall(pro->dep[i]);
		printf("\tInstalling %s\n",  pro->name);
		pro->isInstall = 1;
		recordOrder(pro);
	}
}

void Install(char *proName){
	node *tmp;
	tmp = isExist(proName);
	if(tmp){
		if(tmp->isInstall)
			printf("\t%s is already installed.\n", tmp->name);
		else
			doInstall(tmp);
	}
	else{
		tmp = createNode(proName);
		tmp->isInstall = 1;
		printf("\tInstalling %s\n", tmp->name);
		recordOrder(tmp);
	}
}


int checkRemove(node *pro){
	int check = 1, i;
	node *tmp = list->next;
	while(tmp && check){
		if(tmp->isInstall){
			for(i=0;i<tmp->numDep;i++){
				if(tmp->dep[i]==pro){
					check = 0;
					break;
				}
			}
		}
		tmp = tmp->next;
	}
	return check;
}

void doRemove(node *pro){
	int i;
	if(pro->isInstall && checkRemove(pro)){
		//* if need recursive 
		printf("\tRemoving %s\n", pro->name); // */
		pro->isInstall = 0; 
		for(i=pro->numDep-1;i>=0;i--){
			/*	if do not need recursive
			if(checkRemove(pro->dep[i])){
				printf("\tRemoving %s\n", pro->dep[i]->name);
				pro->dep[i]->isInstall = 0;
			} // */

			//* if need recursive
			if(checkRemove(pro->dep[i]))
				doRemove(pro->dep[i]); // */
		}
	}
}

void Remove(char *proName){
	node *tmp;
	int canRemove;
	tmp = isExist(proName);
	if(!tmp->isInstall)
		printf("\t%s is not installed.\n", tmp->name);
	else if(!checkRemove(tmp))
		printf("\t%s is still needed.\n", tmp->name);
	else{
		/* if do not need recursive
		printf("\tRemoving %s\n", tmp->name); // */
		doRemove(tmp);	
	}
}

void List(){
	record *tmp = order->next;
	while(tmp){
		if(tmp->val->isInstall)
			printf("\t%s\n", tmp->val->name);
		tmp = tmp->next;
	}
}
