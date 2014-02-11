#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    struct _node *next;
    char value;
}node;

node *front = NULL, *back = NULL;
int length = 0, isUsed = 0;

int isEmpty(){
    if(isUsed==0)
        return 1;
    return 0;
}

int isFull(){
    if(isUsed==length)
        return 1;
    return 0;
}

void create(int space){
    int i;
    node *tmp;
    if(length!=0)
        puts("The queue has been created!!");
    length = space;
    tmp = (node*)malloc(sizeof(node)*length);
    for(i=0;i<length-1;i++)
        (tmp+i)->next = (tmp+i+1);
    (tmp+length-1)->next = tmp;
    front = back = tmp;
}

void push(char value){
    if(isFull()==1)
        puts("The queue is full, cannot push any thing!!");
    isUsed++;
    front->value = value;
    front = front->next;
}

char pop(){
    char value;
    if(isEmpty()==1){
        puts("The queue is empty, cannot pop any thing!!");
        return 0;
    }
    isUsed--;
    value = back->value;
    back = back->next;
    return value;
}
