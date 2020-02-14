#include <stdio.h>

void s(int len, int a) {
    if(len > 0) {
        printf("%d\n", a);
        s(len-1, a+1);
    }
}

int main() {
    s(10, 10);
    return 0;
}