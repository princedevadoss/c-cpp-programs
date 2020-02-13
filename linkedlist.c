#include <stdio.h>

struct node {
    int data;
    struct node *next; 
};

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

struct node* createNode(int data) {
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct node* traverse(struct node *traverseNode, int pos) {
    for(int i=0; i<pos; i++) {
        traverseNode = traverseNode -> next;
    }
    return traverseNode;
}

int main() {
    struct node *p, *q, *pnode, *pnode1, *pnode2, *pnode3;
    int n, pos, value;
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
       p=p->next;
    }

    p = q;
    p = traverseLastNode(p);

    //Insertion at begining
    pnode = createNode(60);

    pnode->next = q;
    q = pnode;

    //Insertion at end
    pnode1 = createNode(70);

    p->next = pnode1;

    //Insertion at given position
    pnode2 = createNode(80);
    pnode3 = createNode(90);

    scanf("%d", &pos);

    p=q;
    p = traverse(p, pos);

    pnode2->next = pnode3;
    pnode3->next = p->next;
    p->next = pnode2;

    p=q;
    printf("\nAfter Inserting\n");
    printNodes(p);
    return 0;
}