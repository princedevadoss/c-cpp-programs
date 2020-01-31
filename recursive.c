#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int recursive(int *ar, int len) {
    if(len > 0) {
        swap((ar+len), (ar+(len-1)));
        recursive(ar, len-1);
    }
}
int main() {
    int *a;
    a=malloc(2);
    *a=90;
    *(a+1)=32;
    *(a+2)=43;
    *(a+3)=34;
    *(a+4)=15;
    recursive(a, 4);
    printf("%d\t%d\t%d\t%d\t%d\n", *(a),*(a+1),*(a+2),*(a+3),*(a+4));
    return 0;
}