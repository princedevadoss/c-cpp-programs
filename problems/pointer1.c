#include <stdio.h>

int** returner(int *d) {
    return &(d);
}
int main() {
    int *s, *t, **p, m=22;
    s=malloc(2);
    *s=10;
    *(s++) = 20;
    *(s++) = 30;
    t=s;
    p = &s;
    *p=&m;
    p=returner(t-1);
    printf("%d,%d,%d,%d,%d\n", *s, *t, *(t-1), *(t-2), *(*p-1));
    return 0;
}