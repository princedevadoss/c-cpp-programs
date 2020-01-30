#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a, *b, s=20;
    a=&s;
    b=malloc(sizeof(int));
    *b = 70;
    printf("%d\t%d\n", *a, *b);
    return 0;
}