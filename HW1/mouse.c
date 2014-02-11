#include <stdio.h>
#include <stdlib.h>
#include "mouse.h"


typedef struct _site{
	int row, col, dir;
	struct _site *next, *last;
}site;

site walk, *stack, *cur = NULL;

void mListStack(){
	site *tmp = cur;
	while(tmp -> last != stack)
		tmp = tmp -> last;
	while(tmp != NULL){
		printf("Row: %d, Col: %d, Dir: %d\n", tmp->row, tmp->col, tmp->dir);			
		tmp = tmp -> next;
	}
}

void push(int row, int col, int dir){
	site *tmp = (site*)malloc(sizeof(site));
	tmp -> col = col;
	tmp -> row = row;
	tmp -> dir = dir;
	tmp -> last = cur;
	tmp -> next = NULL;
	cur -> next = tmp;
	cur = tmp;
	walk.col = col;
	walk.row = row;
	walk.dir = dir;
	printf("push(%d, %d, %d):\n", row, col, dir);
}

void mSetStart(){
        stack = (site*)malloc(sizeof(site));
        cur = stack;
        push(1, 1, 0);
}


int isEmpty(){
	if(cur==stack)
		return 1;
	return 0;
}

site pop(){
        site *tmp;
        tmp = cur;
        if(isEmpty()){
                printf("There is no route can cwalk.\n");
                tmp -> col = -1;
                tmp -> row = -1;
                tmp -> dir = -1;
                tmp -> next = NULL;
                tmp -> last = NULL;
        }
        else if(cur->last!=NULL){
                cur->last->next = NULL;
                cur = cur->last;
        }
        else{
                cur = NULL;
        }
        if(tmp->col==walk.col && tmp->row==walk.row){
                tmp = cur;
                if(isEmpty()){
                        printf("There is no route can cwalk.\n");
                        tmp -> col = -1;
                        tmp -> row = -1;
                        tmp -> dir = -1;
                        tmp -> next = NULL;
                        tmp -> last = NULL;
                }
                else if(cur->last!=NULL){
                        cur->last->next = NULL;
                        cur = cur->last;
                }
                else{
                        cur = NULL;
                }
        }
        printf("pop() = %d, %d, %d: \n", tmp->row, tmp->col, tmp->dir);
        return *tmp;

}

int mWalk(char (*map)[500], int *row, int *col){
        int i, mR[] = {-1, -1, 0, 1, 1, 1, 0,-1}, mC[] = {0, 1, 1, 1, 0, -1, -1, -1}, has_walk = 0;;
        map[walk.row][walk.col] = 'm';
        for(i=0;i<8&&has_walk!=1;i++){
                if(map[walk.row+mR[i]][walk.col+mC[i]]!='1' && map[walk.row+mR[i]][walk.col+mC[i]]!='m'){
                        walk.row += mR[i];
                        walk.col += mC[i];
                        walk.dir ++;
			if(map[walk.row][walk.col] == 'S')
				return 1;
                        *row = walk.row;
                        *col = walk.col;
                        has_walk = 1;
                }
        }
        if(has_walk==0)
                walk = pop();
        else
                push(walk.row, walk.col, walk.dir);
	return 0;
}

