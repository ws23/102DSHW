#include <stdio.h>
#include <stdlib.h>
#include "sol.h"

int main(){

	int n, start;
	scanf("%d %d", &n, &start);
	create(n);
//	show();
	call(start);
	return 0;
}
