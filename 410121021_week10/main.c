#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    int value;
    char c;
    while(scanf("%d%c", &value, &c)!=EOF){
        Insert(value);
        //Show();
        if(c!=',')
            break;
    }
    while(!IsEmpty())
        Delete();
    ShowAll();

    return 0;
}
