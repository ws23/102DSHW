#include <stdio.h>
#include "DLinked.h"

int main()
{
    node *current;
    Create();
    current = First();
    printf("current: %x\n", current);
    /*
        The Output Format is "the last address of current" <- "the address of current" -> "the next address of current"
    */


    // Insert
    printf("\nTest Insert: \n");
    Insert(current, 1);
    printf("%x<-%x->%x\n", Pror(current), current, Next(current));
    current = Next(current);
    printf("%x<-%x->%x\n", Pror(current), current, Next(current));

    current = Pror(current);
    Insert(current, 2);
    printf("%x<-%x->%x\n", Pror(current), current, Next(current));
    current = Next(current);
    printf("%x<-%x->%x\n", Pror(current), current, Next(current));
    current = Next(current);
    printf("%x<-%x->%x\n", Pror(current), current, Next(current));

    // Delete
    printf("\nTest Delete: \n");
    current = Tail();
    printf("%x<-%x->%x\n", Pror(current), current, Next(current));
    current = Delete(current);
    printf("%x<-%x->%x\n", Pror(current), current, Next(current));



    return 0;
}
