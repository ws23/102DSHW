#include <stdio.h>
#include "stack.h"

int main(){
    char s[10000];
    int i, r;

    while(scanf("%s", s)!=EOF){
        for(i=0;s[i];i++){
            if(s[i]=='(')
                push(s[i]);
            else{
                r = pop();
                if(r==0){
                    printf("0\n");
                    break;
                }
            }
        }
        if(r==2)
            printf("1\n");
        else if(r!=0){
            r = pop();
            printf("%d\n", r==0?1:0);
        }
        tofree();
    }
    return 0;
}
