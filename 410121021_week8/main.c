#include <stdio.h>
#include <string.h>
#include "tree.h"

int main(){
    char s[1000];
    int len, i;
    create();
    gets(s);
    for(i=0;i<strlen(s);i++)
        add(s[i]);
    printInOrder();
    return 0;
}
