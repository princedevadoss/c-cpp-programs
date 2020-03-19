#include <stdio.h>

int main() {
    int ar[100];
    int le, n, l, r, v;
    printf("Enter length and tasks count\n");
    scanf("%d%d", &le, &n);
    printf("Enter the array values\n");
    for(int i=0;i<le;i++) {
        scanf("%d", &ar[i]);
    }

    for(int j=0;j<n;j++) {
        printf("Enter L R V\n");
        scanf("%d%d%d", &l, &r, &v);
        for(int h=l-1;h<r;h++) {
            ar[h] = ar[h] & v;
        }
    }
    for(int m=0;m<le;m++) {
        printf("%d\t", ar[m]);
    }
    return 0;
}