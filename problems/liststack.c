#include <stdio.h> 
#include <stdlib.h> 
struct node
{
  int data;
  struct node *link;
}*top,*top1,*temp; 
int topelement(); 
void push(int x); 
void pop();
void display(); 
int count = 0; 
void main()
{
int no, ch, e; 
printf("\n 1 - Push");
printf("\n 2 - Pop");
printf("\n 3 - Top");
printf("\n 4 - Exit"); 
printf("\n 5 - Dipslay");
create(); 
while (1)
{
printf("\n Enter choice : "); 
scanf("%d", &ch);
switch (ch)
{
case 1:
 printf("Enter data : "); 
 scanf("%d", &no); 
 push(no);
 break; 
case 2:
 pop(); 
 break;
case 3:
 if (top == NULL)
 {
    printf("No elements in stack");
 }
else
{
 e = topelement();
 printf("\n Top element : %d", e);
}
case 4:
 exit(0); 
case 5:
  display(); 
  break;
default :
  printf(" Wrong choice, Please enter correct choice "); 
  break;
}
}
}
void push(int x)
{
if (top == NULL)
{
 top =(struct node *malloc(sizeof(struct node)); 
 top->link= NULL;
 top->data = x;
}
else
{
 temp =(struct node *malloc(sizeof(struct node)); 
 temp->link= top;
 temp->data = x; 
 top = temp;
}
count++;
}

void display()
{
 top1 = top;
if (top1 == NULL)
{
 printf("Stack is empty"); 
 return;
}
while (top1 != NULL)
{
  printf("%d ", top1->data); 
  top1 = top1->link
}
}
 void pop()
{
top1 = top;
if (top1 == NULL)
{
 printf("\n Error");
  return;
}
else
{
     top1 = top1->link;
    printf("\n Popped value : %d", top->data); 
    free(top);
    top=top1;
    count--;
}
int topelement()
{
return(top->data);
}

