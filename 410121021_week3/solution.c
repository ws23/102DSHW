#include "solution.h"
#include <string.h>
#include <stdio.h>

void showMatrix(matrix M[], int n, int m, int N){
    int i, j, count = 0;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(j!=0)
                putchar(' ');
            if(count>N){
                putchar('0');
                continue;
            }
            if(M[count].row==i+1&&M[count].col==j+1){
                printf("%d", M[count].val);
                count++;
            }
            else
                putchar('0');
        }
        printf("\n");
    }
}

void setTrans(matrix ori[], matrix trans[], int count){
    int i;
    for(i=0;i<count;i++){
        trans[i].col = ori[i].row;
        trans[i].row = ori[i].col;
        trans[i].val = ori[i].val;
    }
}

int setMulti(matrix ori[], matrix trans[], matrix multi[], int row, int col, int count){
    int i, j, k, temp, multiCount;
    multiCount = 0;
    memset(multi, 0, sizeof(multi));
    for(i=0;i<col;i++){
        for(j=0;j<col;j++){
            temp = 0;
            for(k=0;k<row;k++)
                temp += getVal(i+1, k+1, ori, count) * getVal(k+1, j+1, trans, count);
            if(temp!=0){
                multi[multiCount].val = temp;
                multi[multiCount].row = i+1;
                multi[multiCount].col = j+1;
                multiCount++;
            }
        }
    }
    return multiCount;
}

int getVal(int row, int col, matrix A[], int count){
    int i;
    for(i=0;i<count;i++){
        if(A[i].row==row && A[i].col==col)
            return A[i].val;
    }
    return 0;
}



