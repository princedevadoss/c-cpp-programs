#include <stdio.h>
#include <stdlib.h>
struct s {
    int *a;
    float b;
    char c;
};
void main() {
    struct s *a1;
    a1=malloc(7);
    a1->a = malloc(2);
    *(a1->a)=10;
    a1->b=20.5;
    a1->c='a';
    printf("%d\t%f\t%c\n",*(a1->a),a1->b,a1->c);
}