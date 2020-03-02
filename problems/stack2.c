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
void pop()
{
    struct node*temp;
    temp=top;
    if(top==NULL)
    {
        printf("no popped elements");

    }
    else
    {
        printf("%d",top->data);
        top=temp->link;
        free(temp);
    }
    
}
int main() 
{
	struct node *top , *newnode;
	int n , ch;
	top = NULL;
	while(1)
	{
	
	printf("\nEnter the operation number \n1.PUSH  \n2.POP \n3.DISPLAY STACK\n");
	scanf("%d" , &ch);
	if(ch == 1)
	{
		printf("\nEnter the element   ");
		scanf("%d",&n);
		top= push(n,top);	
	}
	else if(ch == 2)
	{
		top= pop(top);
	}
	else if(ch == 3)
	{
		newnode =top;
		printf("\nStack =>");
		while( top!= NULL)
		{
			printf("\n%d" , top -> data);
			top = top -> link;
		}
		top = newnode;
	}
	
	}
	 
	return 0;
}

	 