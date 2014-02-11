typedef struct _site site;

void cSetStart(int);

void cListStack();
int cisEmpty();
void cpush(int, int, int);
site cpop();

int cWalk(char (*)[500], int*, int*);

