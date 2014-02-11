typedef struct _node{
	int val; 
	struct _node *next, *pre;
}node;

void insertHead(int);
void insertTail(int);
int removeHead();
int removeTail();
void Swap();
