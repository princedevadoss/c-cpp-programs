#include <stdio.h>

struct s {
    int a;
    int *b;
    int *c;
};

int main() {
    int a = 10, b=80;
    struct s a1;
    a1.a = 20;
    a1.b = &a;
    a1.c = a1.b;
    a1.c = &(a1.a);
    a1.b = &b;
    printf("%d, %d, %d, %d, %d\n", a, b, a1.a, *a1.b, *a1.c);
    return 0;
}