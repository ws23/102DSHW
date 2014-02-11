#include <stdio.h>
#include <string.h>
#include "map.h"
#include "mouse.h"
#include "cat.h"

int main(){
	char map[500][500];
	int result, mCol = -1, mRow = -1, cCol = -2, cRow = -2;
	memset(map, '1', sizeof(map));
	setMap(map);
	mSetStart();
	cSetStart(strlen(map[1])-2);
	while(1){
		result = mWalk(map, &mRow, &mCol);
		if(result){
			printf("Get to the mouse's hole!!\n");
			showMap(map);
			break;
		}
		if(cCol==mCol && cRow==mRow){
			map[cRow][cCol] = ' ';
			printf("Cat have caught the mouse!!\n");
			showMap(map);
			break;
		}
		result = cWalk(map, &cRow, &cCol);
		if(cCol==mCol && cRow==mRow){
			map[cRow][cCol] = ' ';
			printf("Cat have caught the mouse!!\n");
			showMap(map);
			break;	
		}
	}
	return 0;
}
