/*
    Implemented Structure with Pointer
*/
#include <stdio.h>
#include <stdlib.h>

struct st{
    int *m;
    float a;
    char p;
};
    
int main()
{
    struct st r,*r1;
    r1=&r;
    r.p = 'h';
    r.a=90.9;
    r.m=(int *)malloc(sizeof(int));
    *r.m=90;
    printf("%d\t%f\t%c\n",*r1->m,r.a,r1->p);
    
    return 0;
}
