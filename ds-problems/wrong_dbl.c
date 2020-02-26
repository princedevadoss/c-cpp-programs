#include <stdio.h>
#include <stdlib.h>
#include "dbl_common.h"

void specialPrintNode(struct node *p, struct node *ptr) {
    while(p!=NULL) {
        printf("\n%d", p->data);
        p = p->next;
        if(ptr!=NULL && ptr->next!=NULL){
            ptr = ptr -> next -> next;
        }
        if(p==ptr) {
            printf("\n%d", p->data);
            break;
        }
    }
}

void specialPrintReverseNode(struct node *p, struct node *ptr) {
    while(p!=NULL) {
        printf("\n%d", p->data);
        p = p->prev;
        if(ptr!=NULL && ptr->prev!=NULL){
            ptr = ptr -> prev -> prev;
        }
        if(p==ptr) {
            printf("\n%d", p->data);
            break;
        }
    }
}

void correctDBL(struct node *p, struct node *last) {
    if(p->next!=NULL) {
        if(p->next->prev==p) {
            correctDBL(p->next, last);
        }
        else {
            int s=0;
            struct node *ptr2;
            ptr2=last;
            while(last->prev!=NULL || last!=ptr2) {
                if(last->prev==p) {
                    p->next=last;
                    s=1;
                }
                last = last->prev;
                if(ptr2!=NULL && ptr2->prev!=NULL){
                    ptr2 = ptr2 -> prev -> prev;
                }
            }
            if(s==0) {
                p->next->prev = p;
            }
        }
    }
}

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
    temp -> next = last;

    p=q;
    printf("\n Forward...\n");
    specialPrintNode(p, p);

    printf("\n Reverse...\n");
    specialPrintReverseNode(last, last);

    p=q;
    correctDBL(p, last);

    p=q;
    printf("\n Forward...\n");
    printNodes(p);

    p = traverseLastNode(p);
    printf("\nBackward\n");
    printNodesReverse(p);

    return 0;
}
