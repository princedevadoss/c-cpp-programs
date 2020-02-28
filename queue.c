#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next; 
};
struct node* pop(struct node *list) {
    struct node *temp;
    temp = list -> next;
    free(list);
    return temp;
}
void printNodes(struct node *p) {
    while(p != NULL) {
        printf("%d\n", p->data);
        p=p->next;
    }
}
struct node* traverseLastNode(struct node *traverseNode) {
    while(traverseNode->next != NULL) {
        traverseNode = traverseNode -> next;
    }
    return traverseNode;
}

struct node* createNode(int data) {
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insertAtLast(struct node *src, struct node *pnode) {
    src = traverseLastNode(src);
    src->next = pnode;
}

int main() {
    struct node *p, *q, *pnode;
    int n, pos, value;
    scanf("%d", &n);

    //Creating first node outside the loop.
    scanf("%d", &value);
    p = createNode(value);
    q=p;

    //Creating remaining nodes
    for(int i=1;i<n;i++) {
       scanf("%d", &value);
       p->next = createNode(value);
       p=p->next;
    }

    //Insertion at begining
    pnode= createNode(70);
    insertAtLast(p, pnode);
    printf("\nAfter push\n");
    p=q;
    printNodes(p);
    p=q;
    q = pop(q);

    p=q;
    printf("\nAfter pop\n");
    printNodes(p);


return 0;
}