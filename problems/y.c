#include <stdio.h>

int main() {
    int n;
    int c[100], w, tot=0, counter=1;
    printf("Enter total number of tanks\n");
    scanf("%d", &n);
    printf("Enter the tank capacity\n");
    for(int i=0;i<n;i++) {
        scanf("%d", &c[i]);
    }
    printf("Enter the water capacity\n");
    for(int j=0;j<n;j++) {
        scanf("%d", &w);
        tot += w;
    }
    for(int k=0; k<n; k++) {
        for(int m=k+1; m<n; m++) {
            if(c[k]<c[m]) {
                int temp = c[k];
                c[k] = c[m];
                c[m] = temp;
            }
        }
    }
    for(int y=0; y<n; y++) {
        if(tot >= c[y]) {
            tot -= c[y];
            counter++;
        }
        else {
            break;
        }
    }
    printf("Minimum number of tanks required %d\n", counter);
    return 0;
}