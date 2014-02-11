#include <stdio.h>
#include <string.h>

int H, W;

void showMap(char (*map)[500]){
        int i, j;
        for(i=1;i<=H;i++){
                for(j=1;j<=W;j++)
                        putchar(map[i][j]);
                putchar('\n');
        }
}

void setMap(char (*map)[500]){
        char input[500];
        int i, j, h, w;
        i = 1;
        while(gets(input)){
                if(input[0]=='('){
                        sscanf(input, "(%d,%d)", &h, &w);
                        H = i-1;
                        map[h][w] = 'S';
                        break;
                }
                W = strlen(input);
                for(j=1;j<=W;j++)
                        map[i][j] = input[j-1];
		map[i][W+2] = 0;
                i++;
        }
}
