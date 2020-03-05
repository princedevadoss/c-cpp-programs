#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data,newnode;
	struct node *link;
 };
 struct node *top=NULL;
 void push(int x)
 {
     struct node*newnode;
     newnode = (struct node*)malloc(sizeof(struct node));
     newnode->data=x;
     newnode->link=top;
     top=newnode;
	
 }
 void display()
 {
     struct node*temp;
     temp=top;
     if(top==NULL)
     {
         printf("the list is empty");
     }
     else
     {
         while(temp!=NULL)
         {
             printf("%d",temp->data);
             temp=temp->link;
         }
     }
     
 }
void pop(struct node*top)
{
    struct node*temp;
    temp=top;
    temp=top->link;
    top->next=NULL;
    free(temp);
    temp=top;
    while(top->link->link != NULL) {
        top=top->link;
    }
    deleteAtLast(top);



}    
int main() 
{
	int no,ch;
	printf("\n 1:push");
	printf("\n 2:pop");
	printf("n 3:display");
create();
while(1) 
 { 
	printf("\n enter choice:");
	scanf("%d",&ch);
switch(ch)
{
	case1:
	 printf("enter data");
	 scanf("%d",&no);
	 push(no);
	 break;
	case2:
	 pop();
	 break;
	case3:
	 display();
	 break;
	default:
	 printf("wrong choice");
	 break;
	
 }
}
}	
	 