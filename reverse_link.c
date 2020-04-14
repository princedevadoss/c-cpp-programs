#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next; 
};

struct node* findNode(struct node *tr, struct node *find) {
    if(tr->next != find) {
        return findNode(tr->next, find);
    }
    else {
        return tr;
    }
}

void deleteAtPos(struct node *list, int pos) {
    struct node *temp;
    for(int i=0; i<pos-2; i++) {
        list = list->next;
    }
    temp = list->next;
    list->next = list->next->next;
    free(temp);
}

void deleteAtLast(struct node *last) {
    struct node *temp;
    temp = last->next;
    last->next = NULL;
    free(temp);
}
struct node* deleteAtFirst(struct node *list) {
    struct node *temp;
    temp = list -> next;
    free(list);
    return temp;
}

struct node* findMid(struct node *source, struct node *copy) {
    if(source->next == NULL) {
        return copy;
    } 
    else if(source->next->next == NULL) {
        return copy;
    }
    else {
        return findMid(source->next->next, copy->next);
    }
}

struct node* reverse(struct node *source, struct node *dest) {
    if(source->next != NULL) {
        struct node *initial;
        initial = source;
        while(source->next->next != NULL) {
            source = source -> next;
        }
        dest->next = source;
        source->next = NULL;
        return reverse(initial, dest->next);
    }
    else {
        return source;
    }
}

int getLength(struct node *curr) {
    if (curr->next != NULL) {
        return 1 + getLength(curr->next);
    }
    else {
        return 1;
    }
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

void insertAtLast(struct node *src, struct node *pnode) {
    src = traverseLastNode(src);
    src->next = pnode;
}

struct node* insertAtBegining(struct node *p, struct node *pnode) {
    pnode->next = p;
    return pnode;
}

int main() {
    struct node *p, *q, *pnode, *pnode1, *pnode2, *pnode3, *midPrev, *mid, *midNext, *last;
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

    //Insertion at begining
    pnode = createNode(60);
    q = insertAtBegining(q, pnode);

    // Insertion at end
    pnode1 = createNode(70);
    insertAtLast(p, pnode1);

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
    p = q;

    // new = traverseLastNode(p);
    // reverse(p, new);
    // p=q=new;
    
    last = traverseLastNode(p);
    q = reverse(q, last);
    p = q = last;

    printf("\nTotal Nodes %d", getLength(p));
    printf("\nAfter Doing Operation\n");
    printNodes(p);

    p=q;
    q = deleteAtFirst(q);

    p=q;
    printf("\nAfter Deleting at first\n");
    printNodes(p);

    p=q;
    while(p->next->next != NULL) {
        p=p->next;
    }
    deleteAtLast(p);

    p=q;
    scanf("%d", &pos);
    deleteAtPos(p, pos);

    p=q;
    printf("\nAfter Deleting at last\n");
    printNodes(p);

    p=q;
    int h = getLength(q);
    if(h%2 == 0) {
        for(int i=0; i<(h/2)-1; i++) {
            p = p->next;
        }
        printf("\nMid Node is %d\n", p->data);
    }
    else {
        for( int i=0;i<h/2; i++) {
            p = p -> next;
        }
        printf("\nMid Node is %d\n", p->data);
    }
    return 0;
}