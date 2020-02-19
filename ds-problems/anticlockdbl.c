#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev; 
};

struct node* anticlock(struct node *src, struct node *last, int n) {
    if (n > 0) {
        struct node* temp;
        temp = src -> next;
        temp -> prev = NULL;
        src->next = NULL;
        src -> prev = last;
        src -> prev -> next = src;
        last = src;
        return anticlock(temp, last, n-1);
    }
    else {
        return src;
    }
}

struct node* createNode(int data) {
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

struct node* traverseLastNode(struct node *traverseNode) {
    while(traverseNode->next != NULL) {
        traverseNode = traverseNode -> next;
    }
    return traverseNode;
}

void printNodes(struct node *p) {
    while(p != NULL) {
        printf("%d\n", p->data);
        p=p->next;
    }
}

void printNodesReverse(struct node *p) {
    while(p != NULL) {
        printf("%d\n", p->data);
        p=p->prev;
    }
}

int main() {
    struct node *p, *q, *last;
    int n, value, num;
    scanf("%d", &n);

    //Creating first node outside the loop.
    scanf("%d", &value);
    p = createNode(value);

    //Assigning first node to q so the after p moves to the last node while creation, q will be the starting node.
    q=p;

    //Creating remaining nodes
    for(int i=1;i<n;i++) {
       scanf("%d", &value);
       p->next = createNode(value);
       p->next->prev = p;
       p=p->next;
    }
    p = q;
    printf("\nEnter the number of rotations in anti clockwise...\n");
    scanf("%d", &num);
    last = traverseLastNode(p);
    q = anticlock(p, last, num);

    p=q;
    printf("\n Forward...\n");
    printNodes(p);

    p = traverseLastNode(p);
    printf("\nBackward\n");
    printNodesReverse(p);

    return 0;
}
