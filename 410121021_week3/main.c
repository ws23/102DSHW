#include <stdio.h>
#include "solution.h"

int main(){
	int n, m, i, N;
	char s[100];
	matrix origin[10000], trans[10000], multi[10000];
    scanf("%d %d ", &n, &m);
    i = 0;
    while(gets(s)){
        if(s[0]==NULL)
            break;
        sscanf(s, " (%d:%d)=%d", &origin[i].row, &origin[i].col, &origin[i].val);
        i++;
    }
    setTrans(origin, trans, i);
    N = setMulti(origin, trans, multi, n, m, i);
    showMatrix(multi, n, n, N);
    return 0;
}
