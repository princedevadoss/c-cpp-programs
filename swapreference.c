/*
    Swapping through Passing Reference or Call by Reference.
*/
#include <stdio.h>

void swap(int *m, int *n) {
    int temp;
    temp = *m;
    *m=*n;
    *n = temp;
}
int main()
{
    int a=10,b=20;
    swap(&a,&b);
    printf("%d\t%d\n",a,b);
    return 0;
}