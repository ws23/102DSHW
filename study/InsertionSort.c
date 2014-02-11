#include <stdio.h>

void show(int list[], int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ", list[i]);
}

void insertion_sort(int list[], int n){
	int i, j, next;
	for(i=1;i<n;i++){
		printf("i = %d, ", i);
		next = list[i];
		printf("next = %d: \n", next);
		for(j=i-1;j>=0 && next<list[j];j--){
			list[j+1] = list[j];
			printf("(%d)[", j);
			show(list, n);
			printf("] ");
		}
		list[j+1] = next;
		show(list, n);
		printf("\n\n");
	}
}

int main(){
	int a[5] = {5, 2, 3, 1, 4};
	insertion_sort(a, 5);
	return 0;
}
