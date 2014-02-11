#include <stdio.h>
#include <stdlib.h>

void show(int list[], int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ", list[i]);
}

void merge(int list[], int first, int mid, int last){
	int i, j, k, *tmp;
	tmp = (int*)malloc(sizeof(int)*(last-first+1));
	i = first;
	j = mid+1;
	k = 0;
	while(k<=last-first){
		if(i>mid){
			tmp[k] = list[j];
			j++;
		}
		else if(j>last){
			tmp[k] = list[i];
			i++;
		}
		else if(list[i]<list[j]){
			tmp[k] = list[i];
			i++;
		}			
		else{
			tmp[k] = list[j];
			j++;
		}
		k++;
	}
	for(i=0;i<k;i++)
		list[first+i] = tmp[i];
}


void MergeSort(int list[], int first, int last){
	int mid;
	if(first<last){
		mid = (first+last)/2;
		MergeSort(list, first, mid);
		MergeSort(list, mid+1, last);
		merge(list, first, mid, last);
	}
}


int main(){
	int a[6] = {2, 4, 1, 5, 3, 6};
	MergeSort(a, 0, 5);
	show(a, 6);
	return 0;
}
