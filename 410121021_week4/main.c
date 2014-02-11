#include <stdio.h>
#include <string.h>
#include "solution.h"

int main()
{
    int lenA, lenB, i, inA[300], inB[300], FibNum[300], len;
    char in[300];
    while(gets(in)){
        memset(inA, 0, sizeof(inA));
        memset(inB, 0, sizeof(inB));
        memset(FibNum, 0, sizeof(FibNum));
        lenA = strlen(in);
        for(i=lenA-1;i>=0;i--)
            inA[lenA-i-1] = in[i] - '0';
        gets(in);
        lenB = strlen(in);
        for(i=lenB-1;i>=0;i--)
            inB[lenB-i-1] = in[i] - '0';
        len = sumUp(inA, inB, FibNum, lenA, lenB);
        len = toFib(FibNum, len);
        for(i=len-1;i>=0;i--)
            printf("%d", FibNum[i]);
        putchar('\n');
    }


    return 0;
}
