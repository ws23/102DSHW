#include <stdio.h>
#include "Queue.h"
#define MAX 100

int main(){
    char s[MAX];
    int i;
    create(MAX);
    while(gets(s)){
        for(i=0;s[i];i++)
            push(s[i]);
        for(i=0;s[i];i++)
            printf("%c", pop());
        putchar('\n');
    }
    return 0;
}
