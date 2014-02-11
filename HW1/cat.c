#include <stdio.h>
#include <stdlib.h>
#include "cat.h"

typedef struct _site{
	int row, col, dir;
	struct _site *next, *last;
}site;


site cwalk, *cstack, *ccur = NULL;

void cListStack(){
	site *tmp = ccur;
	while(tmp -> last != cstack)
		tmp = tmp -> last;
	while(tmp != NULL){
		printf("Row: %d, Col: %d, Dir: %d\n", tmp->row, tmp->col, tmp->dir);			
		tmp = tmp -> next;
	}
}

void cpush(int row, int col, int dir){
	site *tmp = (site*)malloc(sizeof(site));
	tmp -> col = col;
	tmp -> row = row;
	tmp -> dir = dir;
	tmp -> last = ccur;
	tmp -> next = NULL;
	ccur -> next = tmp;
	ccur = tmp;
	printf("cpush(%d, %d, %d):\n", row, col, dir);
}

void cSetStart(int W){
        cstack = (site*)malloc(sizeof(site));
        ccur = cstack;
	cwalk.row = 1;
	cwalk.col = W;
	cwalk.dir = 0;
        cpush(1, W, 0);
}


int cisEmpty(){
	if(ccur==cstack)
		return 1;
	return 0;
}
site cpop(){
	site *tmp;
	tmp = ccur;
	if(cisEmpty()){
		printf("There is no route can cwalk.\n");
		tmp -> col = -1;
		tmp -> row = -1;
		tmp -> dir = -1;
		tmp -> next = NULL;
		tmp -> last = NULL;
	}
	else if(ccur->last!=NULL){
		ccur->last->next = NULL;
		ccur = ccur->last;
	}
	else{
		ccur = NULL;
	}
	if(tmp->col==cwalk.col && tmp->row==cwalk.row){
		tmp = ccur;
		if(cisEmpty()){
			printf("There is no route can cwalk.\n");
			tmp -> col = -1;
			tmp -> row = -1;
			tmp -> dir = -1;
			tmp -> next = NULL;
			tmp -> last = NULL;
		}
		else if(ccur->last!=NULL){
			ccur->last->next = NULL;
			ccur = ccur->last;
		}
		else{
			ccur = NULL;
		}
	}

	printf("cpop() = %d, %d, %d: \n", tmp->row, tmp->col, tmp->dir);
	return *tmp;
}

int cWalk(char (*map)[500], int *row, int *col){
	int i, mR[] = {-1, -1, 0, 1, 1, 1, 0, -1}, mC[] = {0, 1, 1, 1, 0, -1, -1, -1}, has_walk = 0;;	
	map[cwalk.row][cwalk.col] = 'c';
	for(i=0;i<8&&has_walk!=1;i++){
		if(map[cwalk.row+mR[i]][cwalk.col+mC[i]]!='1' && map[cwalk.row+mR[i]][cwalk.col+mC[i]]=='m'){
			cwalk.row += mR[i];
			cwalk.col += mC[i];
			cwalk.dir ++;
			*row = cwalk.row;
			*col = cwalk.col;
			has_walk = 1;
		}
	}	
	for(i=0;i<8&&has_walk!=1;i++){
		if(map[cwalk.row+mR[i]][cwalk.col+mC[i]]!='1' && map[cwalk.row+mR[i]][cwalk.col+mC[i]]!='c'){
                        cwalk.row += mR[i];
                        cwalk.col += mC[i];
                        cwalk.dir ++;
                        *row = cwalk.row;
                        *col = cwalk.col;
			has_walk = 1;
		}
	}
	if(has_walk==0)
		cwalk = cpop();
	else
		cpush(cwalk.row, cwalk.col, cwalk.dir);

	return 0;
}

