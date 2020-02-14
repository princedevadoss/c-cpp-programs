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
//to print the middle element

    struct node *slow_ptr = q;
    struct node *fast_ptr = q;
 
    if (q!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}
