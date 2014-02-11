#ifndef __SOLUTION__
#define __SOLUTION__

typedef struct{
	int row, col, val;
}matrix;

void showMatrix(matrix M[], int n, int m, int N);
void setTrans(matrix ori[], matrix trans[], int count);
int setMulti(matrix ori[], matrix trans[], matrix multi[], int n, int m, int count);
int getVal(int row, int col, matrix A[], int count);

#endif

