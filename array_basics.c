#include <stdio.h>

void add(int arr[], int n) {
    int count = 0;
    for(int i=0; i<n; i++) {
        if(i % 2 == 0){
            count = count + arr[i];
        }
        else {
            count = count - arr[i];
        }
    }
    if(count < 0) {
        printf("false\n");
    }
    else {
        printf("true\n");
    }
}

int main() {
    int a[]= {2, 2, 5, 6, 0};
    add(a, 5);
    return 0;
}