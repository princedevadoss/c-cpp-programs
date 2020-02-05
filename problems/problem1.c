#include <stdio.h>

int next(int *src, int len, int count, int pred, int checker, int m) {
    if (m<len-1) {
        if((pred == 0 && *(src)+1 == checker) || (pred == 2 &&*(src)+1 == checker) || checker == *(src)) {
            pred = 1;
            checker = *(src);
            return next(src+1, len, count+1, pred, checker, m+1);
        }
        else if((pred == 0 && *(src)-1 == checker) || (pred == 1 && *(src)-1 == checker) || checker == *(src)) {
            pred = 2;
            checker = *(src);
            return next(src+1, len, count+1, pred, checker, m+1);
        }
        else {
            return next(src+1, len, count, pred, checker, m+1);
        }
    }
    else {
        return count;
    }
}

int router(int *src, int nexter, int length, int *arr, int count) {
    int result;
    if(nexter<length) {
        result = next(src+nexter, length, 0, 0, *src, nexter);
        if(result > 0) {
            printf("%d\t", result);
            *arr = result;
            return router(src, nexter+1, length, arr+1, count+1);
        }
        else {
            return router(src, nexter+1, length, arr, count);
        }
    }
    else {
        return count;
    }
}

int finder(int *src, int start, int length, int *arr, int count) {
    int res;
    if(start<length) {
        res = router(src, 1, length, arr, count);
        count = res;
        arr += res;
        printf("res ---- > %d, %d\n", res, count);
        return finder(src+1, start+1, length, arr, count);
    }
    else {
        return count;
    }
}
int main() {
    int *arr, result, *src, n, max=0;
    arr=malloc(2);
    src=malloc(2);
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", src+i);
    }
    result=finder(src, 0, n, arr, 0);
    for(int j=0;j<result;j++) {
        if(*(arr+j) > max) {
            max = *(arr+j);
        }
    }
    for (int j=0;j<result; j++) {
        printf("%d,", *(arr+j));
    }
    printf("\nResult is %d\n", result);
    return 0;
}