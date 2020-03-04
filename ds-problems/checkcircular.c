#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev; 
};

void checkList(struct node *p) {
    struct node *t2;
    int val = 1;
    t2=p;
    if(p->prev != NULL) {
        printf("\nCircular");
        val=0;
    }
    while(val) {
        t2 = t2 -> next -> next;
        p = p->next;
        if(t2 -> next == NULL) {
            printf("\nDouble linked list");
            val = 0;
        }
        else if(p == t2) {
            printf("\nSub circular");
            val = 0;
        }
    }
}

struct node* traverseLastNode(struct node *traverseNode, struct node *q) {
    while(traverseNode->next != q) {
        traverseNode = traverseNode -> next;
    }
    return traverseNode;
}

struct node* traverse(struct node *traverseNode, int pos) {
    for(int i=0; i<pos; i++) {
        traverseNode = traverseNode -> next;
    }
    return traverseNode;
}

struct node* createNode(int data) {
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void printNodes(struct node *p,  struct node *q) {
    int count = 0;
     while(p != NULL) {
        printf("%d\n", p->data);
        p=p->next;
    }
}

void printCountNodes(struct node *p,  struct node *q, int count) {
    if (count>0) {
        do {
            printf("%d\n", p->data);
            p=p->next;
        } while(p != q);
        printCountNodes(p, q, count-1);
    }
}

void printNodesReverse(struct node *p, struct node *q) {
    do {
        printf("%d\n", p->data);
        p=p->prev;
    } while(p->next != q);
}

int main() {
    struct node *p, *q, *temp;
    int n, value;
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
       if(i==2) {
           temp = p;
       }
    }

    p=q;
    checkList(p);


    return 0;
}