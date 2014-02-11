#include "stack.h"

node *top = NULL;
node *buttom;

typedef struct node{
    struct node *next;
    char value;
}node;

void push(char value){
    if(!top){
        top = (node*)malloc(sizeof(node));
        buttom = (node*)malloc(sizeof(node));
        top->value = value;
        top->next = NULL;
        buttom = top;
    }
    else{
        node *tmp = (node*)malloc(sizeof(node));
        tmp -> value = value;
        tmp -> next = NULL;
        top -> next = tmp;
        top = tmp;
    }
}

int pop(){
    node *cur;
    cur = buttom;
    if(top==NULL) // judge is empty
        return 0;
    else{
        cur = buttom;
        while(1){
            if(cur->next==NULL){
                top = NULL;
                 return 2;
            }
            else if(cur->next==top){
                cur->next = NULL;
                top = cur;
                return 1;
            }
            else
                cur = cur->next;
        }
        putchar('\n');
    }
}

void tofree(){
    top = NULL;
}


