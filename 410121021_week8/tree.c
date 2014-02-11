#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


typedef struct _node
{
    int floor,count;
    char value;
    struct _node *left, *right, *dad;
} node;

int count;
node *root, *child;

void create(){
    node *tmp = (node*)malloc(sizeof(node));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->dad = root;
    tmp->value = '#';
    tmp->floor = 0;
    root = child = tmp;
}

void add(char s){
    node *tmp, *temp = (node*)malloc(sizeof(node));
    if(!isdigit(child->value)){
        tmp = child;
        if(root->value=='#')
                root->value = s;
        else{
            while(tmp->left!=NULL)
                    tmp = tmp->left;
            temp->dad = tmp;
            temp->value = s;
            if(isdigit(s))
                temp->count = s-'0';
            temp->left = NULL;
            temp->right = NULL;
            temp->floor = tmp->floor+1;
            tmp->left = temp;
            child = temp;
        }
    }
    else{
        tmp = child;
        while(tmp->right!=NULL || tmp->left==NULL)
            tmp = tmp->dad;
        temp->dad = tmp;
        temp->value = s;
        if(isdigit(s))
                temp->count = s-'0';
        temp->left = NULL;
        temp->right = NULL;
        temp->floor = tmp->floor+1;
        tmp->right = temp;
        child = temp;
    }
}

int CountVal(char s, int a, int b){
    if(s=='+')
        return a+b;
    else if(s=='-')
        return a-b;
    else if(s=='*')
        return a*b;
    else if(s=='/')
        return a/b;
    return 0;
}

void findInOrder(node *n){

    if(n->left!=NULL){
        findInOrder(n->left);
        if(isdigit(n->left->value))
            printf("%c", n->left->value);
        printf("%c", n->value);
    }
    if(n->right!=NULL){
        findInOrder(n->right);
        if(isdigit(n->right->value))
            printf("%c", n->right->value);
        n->count = CountVal(n->value, n->left->count, n->right->count);
    }
}

void printInOrder(){
    findInOrder(root);
    printf("=%d\n", root->count);
}
