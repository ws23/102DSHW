#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    struct _node *last;
    struct _node *next;
    int value;
}node;

node *Head;

void Create(){
    node *tmp = (node*)malloc(sizeof(node));
    tmp->last = NULL;
    tmp->next = NULL;
    Head = tmp;
}

void Insert(node* p, int V){
    node *tmp = (node*)malloc(sizeof(node));
    tmp -> last = p;
    tmp -> next = p -> next;
    p -> next = tmp;
    tmp -> value = V;
}

node* Delete(node* p){
    node *current;
    if(p->last!=NULL)
        p->last->next = p->next;
    if(p->next!=NULL)
        p->next->last = p->last;
    current = (p->next!=NULL)?p->next:p->last;
    free(p);
    return current;
}

node* First(){
    node *tmp = Head;
    while(tmp->last!=NULL)
        tmp = tmp->last;
    return tmp;
}

node* Tail(){
    node *tmp = Head;
    while(tmp->next!=NULL)
        tmp = tmp->next;
    return tmp;
}

node* Pror(node* ptr){
    return ptr->last;
}

node* Next(node* ptr){
    return ptr->next;
}
