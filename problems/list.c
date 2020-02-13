#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    
struct node *next;

};

int main()
{
  
  struct node *p,*q,*pnode1;
 
   int n,pos;
 
   scanf("%d", &n);
 
   p = malloc(sizeof(struct node));
 
   scanf("%d", &(p->data));
  
  q=p;
 
   p->next=NULL;
 
   for(int i=1;i<n;i++)
{
   
      p->next = malloc(sizeof(struct node));

         p=p->next;
    
    scanf("%d", &(p->data));
 
       p->next=NULL;

}
    p=q;

while(p->next != NULL)
{
 
  printf("%d\n",p->data);
 
  p=p->next;

}
//Insertion at given position
pnode1=malloc(sizeof(struct node));
pnode1->data=100;
pnode1->next=NULL;
scanf("%d",&pos);
p=q;
for(int i=0;i<pos;i++){
    p=p->next;
}
pnode1->next=p->next;
p->next=pnode1;
p=q;
printf("\nAfter inserting\n");
while(p!= NULL)
{
    printf("%d\n",p->data);
    p=p->next;
}
return 0;
}

