#include <stdio.h>

int main() {
    int *a, n, total = 0;
    printf("\nEnter the total numbers");
    scanf("%d", &n);
    a = malloc(sizeof(int));
    for(int i=0;i < n; i++) {
        scanf("%d", a+i);
    }
    for(int i=0; i<n; i++) {
        total = total + *(a+i);
    }
    printf("\nTotal is %d\n", total);
    return 0;
}