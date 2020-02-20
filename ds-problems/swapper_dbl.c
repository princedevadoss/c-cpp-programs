#include <stdio.h>
#include <stdlib.h>
#include "dbl_common.h"

struct node* swapper(struct node *p, struct node *first) {
    if(p!=NULL) {
        if(p->next!=NULL) {
            if(first == NULL) {
                first = p->next;
            }
            struct node *next;
            next = p->next->next;
            p->next->next = p;
            p->next->prev = p -> prev;
            if(p->prev != NULL) {
                p -> prev -> next = p -> next;
            }
            p -> prev = p -> next;
            p -> next = next;
            if(next!=NULL) {
                next -> prev = p;
            }
            return swapper(next, first);
        }
        else {
            return first;
        }
    }
    else {
        return first;
    }
}

int main() {
    struct node *p, *q, *first;
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
    p=q;
    q=swapper(p, NULL);

    p=q;
    printf("\n Forward...\n");
    printNodes(p);

    p = traverseLastNode(p);
    printf("\nBackward\n");
    printNodesReverse(p);

    return 0;
}
