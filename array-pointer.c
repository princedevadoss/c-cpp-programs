/*
    Program explains how to create an array with help of pointers and dynamic memory allocation
*/
#include <stdio.h>
#include<stdlib.h>

int main() {
    int a=10,b,*c, n,*i, *j,sum=0;
    i = &a;
    j = malloc(2);
    scanf("%d",&n);
    c=malloc(n*2);
    for(int t=0;t<n;t++) {
        scanf("%d",(c+t));
        sum=sum+*(c+t);
    }
    
    *j=50;
    a=15;
    a=20;
    printf("\n%d\n", sum);
    return 0;
}