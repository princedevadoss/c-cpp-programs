#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev; 
};

void insertAtMiddle(struct node *p, struct node *pnode) {
    pnode -> next = p;
    pnode -> prev = p -> prev;
    p -> prev = pnode;
    pnode -> prev -> next = pnode;
}

struct node* traverseLastNode(struct node *traverseNode) {
    while(traverseNode->next != NULL) {
        traverseNode = traverseNode -> next;
    }
    return traverseNode;
}

struct node* deleteAtFirst(struct node *p) {
    struct node *temp;
    temp = p->next;
    p -> next -> prev = NULL;
    p -> next = NULL;
    free(p);
    return temp;
}

void deleteAtMiddle(struct node *p) {
    struct node *temp;
    temp = p -> next;
    p -> next = temp -> next;
    temp -> next -> prev = p;
    temp -> next = NULL;
    temp -> prev = NULL;
    free(temp);
}

void deleteAtLast(struct node *p) {
    struct node *temp;
    temp = p -> prev;
    temp -> next = NULL;
    p -> prev = NULL;
    free(p);
}
struct node* createNode(int data) {
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
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

void insertAtLast(struct node *src, struct node *pnode) {
    src = traverseLastNode(src);
    src->next = pnode;
    pnode->prev = src;

}

struct node* insertAtBegining(struct node *p, struct node *pnode) {
    pnode->next = p;
    p->prev = pnode;
    return pnode;
}

struct node* traverse(struct node *traverseNode, int pos) {
    for(int i=0; i<pos; i++) {
        traverseNode = traverseNode -> next;
    }
    return traverseNode;
}

int main() {
    struct node *p, *q, *pnode, *pnode2, *pnode3;
    int n, value, pos;
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

    pnode = createNode(60);
    q = insertAtBegining(q, pnode);

    p = q;
    pnode2 = createNode(70);
    insertAtLast(p, pnode2);

    p = q;
    scanf("%d", &pos);

    p = q;
    p = traverse(p, pos);
    pnode3 = createNode(80);
    insertAtMiddle(p, pnode3);

    // p = q;
    // q = deleteAtFirst(p);

    // p = q;
    // p = traverseLastNode(p);
    // deleteAtLast(p);

    // p = q;
    // scanf("%d", &pos);
    // p = traverse(p, pos-2);
    // deleteAtMiddle(p);

    printf("\nPrinting Nodes...\n");
    p = q;
    printNodes(p);

    return 0;
}