#include <stdio.h>
int finder(int element, int *ar, int len, int *m, int count, int *neg, int negcount) {
    if(len >= 0) {
        if (element == *ar) {
            return finder(element, ar+1, len-1, m, count+1, neg, negcount);
        }
        else {
            *neg = *ar;
            return finder(element, ar+1, len-1, m, count, neg+1, negcount+1);
        }
    }
    else {
        *m = element;
        *(m+1) = count;
        return negcount;
    }
}
int calc(int *ar, int len, int *m, int *neg, int counter) {
    if(len>=0) {
        neg = malloc(2);
        len = finder(*ar, ar+1, len-1, m, 1, neg, 0);
        m=m+2;
        counter += 2;
        ar = neg;
        return calc(ar, len-1, m, malloc(2), counter);
    }
    else {
        return counter;
    }
}
int main() {
    int *ar, s, *res, n;
    ar = malloc(2);
    res=malloc(2);
    printf("Enter total number of values?\n");
    scanf("%d", &n);
    printf("Enter the values in order....\n");
    for (int i = 0; i<n; i++) {
        scanf("%d", ar+i);
    }
    s = calc(ar, n-1, res, malloc(2), 0);
    printf("The answer is... \n");
    for(int i=0;i<s;i++) {
        printf("%d\t", *(res+i));
    }
    printf("\n");
    return 0;
}