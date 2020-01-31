#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void array_convert(int *a, int index, int len, int d) {
    if(d>0) {
        if(index<len-1) {
            swap((a+index), (a+index+1));
            array_convert(a, index+1, len, d-1);
        }
        if(index == len-1) {
            swap(a+index, a);
            array_convert(a, 0, len, d-1);
        }
    }
}
int main() {
    int *p;
    p = malloc(2);
    for(int i=0;i<8;i++) {
        *(p+i) = i+1;
        printf("%d\t", *(p+i));
    }
    array_convert(p, 0, 8, 16);
    for(int i=0;i<8;i++) {
        printf("%d\t", *(p+i));
    }
    return 0;
}
