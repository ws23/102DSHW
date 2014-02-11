#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct _node{
    int value, weight;
    struct _node *next;
}node;

int n;
node *bit, *cur;

node binToDec(int b[]){
    int i;
    node dec;
    dec.value = dec.weight = 0;
    for(i=0;i<n;i++){
        dec.value += b[i]*(int)pow(2, i);
        dec.weight += (b[i]==1?1:0);
    }
    dec.next = NULL;
    return dec;
}

void trans(int v){
    int i, j, *tmp, *tmp2, t;
    node *temp, *New;
    t = v;
    tmp = (int*)malloc(sizeof(int)*n);
    tmp2 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        tmp[i] = 0;
    New = (node*)malloc(sizeof(node));
    for(i=0;v;i++){
        tmp[i] = v % 2;
        v /= 2;
    }
    printf("%d: ", t);
    temp = &bit[t];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            tmp2[j] = tmp[j];
        tmp2[i] = (tmp[i]==1?0:1);
        *New = binToDec(tmp2);
        temp->next = New;
        temp = temp->next;
        cur = temp;
        printf("(%d, %d) ", cur->value, cur->weight);
   }
   printf("\n");
}

void create(int size){
    int i, c;
    n = size;
    c = pow(2, n);
    bit = (node*)malloc(sizeof(node)*c);
    memset(bit, 0, sizeof(bit));
    for(i=0;i<c;i++){
        bit[i].next = NULL;
        trans(i);
    }
}
