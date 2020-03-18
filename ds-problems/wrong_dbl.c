#include <stdio.h>
#include <stdlib.h>
#include "dbl_common.h"

int main() {
    struct node *p, *q, *last, *temp;
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
       if(i==2) {
           temp = p;
       }
       p->next->prev = p;
       p=p->next;
    }

    p=q;
    last = traverseLastNode(p);
    temp -> next = last -> prev;

    p=q;
    printf("\n Forward...\n");
    printNodes(p);

    p = traverseLastNode(p);
    printf("\nBackward\n");
    printNodesReverse(p);

    return 0;
}
