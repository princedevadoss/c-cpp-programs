#include <stdio.h>
int sum(int ar[], int len) {
    if(len > 0) {
        return ar[len] + sum(ar, len-1);
    }
    else {
        return ar[len];
    }
}

int main() {
    int ar[] = {5,6,7,8,9,10,12,56};
    printf("%d\n", sum(ar,7));
    return 0;
}