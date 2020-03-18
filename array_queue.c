#include <stdio.h>
#define MAX 5

void printQueue(int arr[], int front, int rear) {
    for(int i=front; i<rear; i++) {
        printf("%d\n", arr[i]);
    }
}

int enque(int *arr, int element, int size) {
    if(size >= MAX) {
        printf ("Please deque an element from queue\n");
        return size;
    }
    else {
        *(arr + size) = element;
        size++;
        printf("%d got inserted", element);
        return size;
    }
}

void deque(int arr[], int *front, int *rear) {
    if(*rear <= 0) {
        printf("Please check the queue size!! Its empty\n");
    }
    else {
        printf("%d Element Got Dequed", arr[*front]);
        *front = *front + 1;
        if(*front == *rear && *front == MAX) {
            *front = *rear = 0;
        }
    }
}

int main() {
    int queue[MAX];
    int val, element, front, rear;
    char c;

    front = rear = 0;
    
    printf("Please Enter the value\n");
    scanf("%c", &c);

    while (c != '!') {
        switch(c) {
            case 'a':
                scanf("%d", &element);
                rear = enque(queue, element, rear);
                break;
            case 'b':
                deque(queue, &front, &rear);
                break;
            case 'c':
                printQueue(queue, front, rear);
        }
        printf("Please Enter the Value");
        scanf("%c", &c);
    }
    return 0;
}