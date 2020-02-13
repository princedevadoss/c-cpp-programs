#include <stdio.h>

struct node {
    int data;
    struct node *next; 
};

int main() {
    struct node *p, *q, *pnode, *pnode1, *pnode2, *pnode3;
    int n, pos;
    scanf("%d", &n);
    p = malloc(sizeof(struct node));
    scanf("%d",&(p->data));
    q=p;
    p->next=NULL;
    for(int i=1;i<n;i++) {
       p->next = malloc(sizeof(struct node));
       p=p->next;
       scanf("%d", &(p->data));
       p->next = NULL; 
    }
    p = q;

while(p->next != NULL) {
    printf("%d\n", p->data);
    p = p->next;
}

//Insertion at begining
pnode = malloc(sizeof(struct node));
pnode->data = 60;
pnode->next = NULL;

pnode->next = q;
q = pnode;

//Insertion at end
pnode1 = malloc(sizeof(struct node));
pnode1->data = 70;
pnode1->next = NULL;

p->next = pnode1;

//Insertion at given position
pnode2 = malloc(sizeof(struct node));
pnode2->data = 80;
pnode2->next = NULL;

pnode3 = malloc(sizeof(struct node));
pnode3->data = 90;
pnode3->next = NULL;

scanf("%d", &pos);

p=q;
for(int i=0; i<pos-1; i++) {
    p = p->next;
}
pnode2->next = pnode3;
pnode3->next = p->next;
p->next = pnode2;

p=q;
printf("\nAfter Inserting\n");
while(p != NULL) {
    printf("%d\n", p->data);
    p = p->next;
}

    return 0;
}