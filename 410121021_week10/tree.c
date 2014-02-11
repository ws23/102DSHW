#include <stdio.h>

int node = 0, heap[1000], all_node = 0;


int IsEmpty(){
    if(node==0)
        return 1;
    return 0;
}

void Swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Sort(){
    int i;
    for(i=node-1;i>=0;i--){
        // only 1 child
        if(i/2==(i-1)/2){
            if(heap[i]>heap[(i-1)/2])
                Swap(&heap[i], &heap[(i-1)/2]);
        }
        // 2 child
        else{
            if(heap[i]>heap[(i-2)/2])
                Swap(&heap[i], &heap[(i-2)/2]);
            else if(heap[i]>heap[(i-1)/2])
                Swap(&heap[i], &heap[(i-1)/2]);
        }
    }
}

void Insert(int value){
    heap[node] = value;
    node++;
    all_node++;
    Sort();
}

void Delete(){
    if(IsEmpty())
        return;
    Swap(&heap[0], &heap[node-1]);
    node--;
    Sort();
}

void ShowAll(){
    int i;
    printf("%d", heap[0]);
    for(i=1;i<all_node;i++)
        printf(",%d", heap[i]);
    printf("\n");
}

void Show(){
    int i;
    printf("%d", heap[0]);
    for(i=1;i<node;i++)
        printf(",%d", heap[i]);
    printf("\n");
}
