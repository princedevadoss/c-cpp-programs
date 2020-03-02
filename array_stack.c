#include <stdio.h>
#define MAX 5

void printStack(int arr[], int length) {
    for(int i=0; i<length; i++) {
        printf("%d\n", arr[i]);
    }
}

int push(int *arr, int element, int size) {
    if(size >= MAX) {
        printf ("Please Pop an element from stack\n");
        return size;
    }
    else {
        *(arr + size) = element;
        size++;
        printf("%d got inserted", element);
        return size;
    }
}

int pop(int arr[], int size) {
    if(size <= 0) {
        printf("Please check the stack size!! Its empty\n");
        return size;
    }
    else {
        printf("%d Element Got Popped", arr[size-1]);
        return size-1;
    }
}

int main() {
    int stack[MAX];
    int val, element, top;
    char c;

    for(int i=0;i<MAX;i++) {
        scanf("%d", &val);
        stack[i] = val;
    }

    top = MAX;
    printStack(stack, MAX);
    printf("Please Enter the value\n");
    scanf("%c", &c);

    while (c != '!') {
        switch(c) {
            case 'a':
                scanf("%d", &element);
                top = push(stack, element, top);
                break;
            case 'b':
                top = pop(stack, top);
                printf("%d", top);
                break;
            case 'c':
                printStack(stack, top);
        }
        printf("Please Enter the Value");
        scanf("%c", &c);
    }
    return 0;
}