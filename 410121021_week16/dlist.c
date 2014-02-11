#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

node *root = NULL, *cur;
int num = 0;

node* createRoot(int value){
	root = (node*)malloc(sizeof(node));
	root->next = NULL;
	root->pre = NULL;
	root->val = value;
	cur = root;
	num++;
	return root;
}

node* createNode(int value){
	if(root==NULL)
		return createRoot(value);
	node *tmp = (node*)malloc(sizeof(node));
	tmp->next = NULL;
	tmp->pre = NULL;
	tmp->val = value;
	cur = tmp;
	num++;
	return cur;
}

node* findHead(){
	node *tmp = root;
	while(tmp->pre!=NULL)
		tmp = tmp->pre;
	return tmp;
}

node* findTail(){
	node *tmp = root;
	while(tmp->next!=NULL)
		tmp = tmp->next;
	return tmp;
}

void show(){
	node *tmp = findHead();
	while(tmp!=NULL){
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
}

void insertHead(int value){
	node *tmp = createNode(value), *head = findHead();
	if(cur!=root){
		head->pre = tmp;
		tmp->next = head;
	}
	//show();
}

void insertTail(int value){
	node *tmp = createNode(value), *tail = findTail();
	if(cur!=root){
		tail->next = tmp;
		tmp->pre = tail;
	}
	//show();
}

void Swap(){
	int i;
	node *head = findHead(), *tail, *tmp;
	tail = head;
	for(i=0;i<num/2;i++)
		tail = tail->next;
	head->pre = findTail();
	tail->pre->next = NULL;
	tail->pre = NULL;
	head->pre->next = head;
	//show();
}

int removeHead(){
	node *tmp = findHead();
	if(num==1){
		int temp = root->val;
		root = NULL;
		num = 0;
		return temp;
	}
	if(tmp==root)
		root = root->next;	
	tmp->next->pre = NULL;
	num--;
	//show();
	return tmp->val;
}

int removeTail(){
	node *tmp = findTail();
	if(num==1){
		int temp = root->val;
		root = NULL;
		num = 0;
		return temp;
	}
	if(tmp==root)
		root = root->pre;
	tmp->pre->next = NULL;
	num--;
	//show();
	return tmp->val;
}
