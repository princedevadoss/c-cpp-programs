#include <stdio.h>

int main() {
    int *a, *b, *c, *d, *e;
    a = malloc(sizeof(int));
    b = malloc(sizeof(int));
    c = a;
    b = d;
    e = a;
    *a = 20;
    *b = 30;
    *c=40;
    *d = 50;
    *e = 60;
    printf("%d, %d, %d, %d, %d, %d", *a, *b, *c, *d, *e);
    return 0;
}