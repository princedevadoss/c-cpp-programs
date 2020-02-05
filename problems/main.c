/*
Practice Program for recusion
*/
#include <stdio.h>

int ger(int p[], int len) {
    if(len > 0) {
        return p[len] + ger(p, len-1) + ger(p, len-2);
    }
    else {
        return 0;
    }
}

int main() {
    int h[]={1,2,3,4,5};
    printf("%d\n", ger(h,4));
    return 0;
}
