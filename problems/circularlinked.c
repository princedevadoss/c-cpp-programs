#include <stdio.h> 
#include <stdlib.h>
struct node
{
int data;
struct node *link;
};
struct node *head = NULL, *x, *y, *z;
void  create(); 
void enqueue();  
void dequeue(); 
void display();
void main()
{
int ch;
printf("\n 1.Creation \n 2.enqueue  ");
printf("\n3.Dequeue \n 4.display"); 
while (1)
 {
{
printf("\n Enter your choice:"); scanf("%d", &ch);
switch(ch)
{
case 1:
 create(); 
 break;
case 2:
 enqueue(); 
 break;
case 3:
 dequeue(); 
 break;
case 4:
 display(); 
 break;
default:
 exit(0);
 }
 }
  } 
void create()
{
  int c;
  x = (struct node*)malloc(sizeof(struct node)); 
  printf("\n Enter the data:");
  scanf("%d", &x->data); 
  x->link = x;
  head = x;
  while (c != 0)
  {
    y = (struct node*)malloc(sizeof(struct node)); 
    printf("\n Enter the data:");
    scanf("%d", &y->data); 
    x->link = y;
    y->link = head; 
    x = y;
  }
  void enqueue()
{
  x = head;
  y = (struct node*)malloc(sizeof(struct node));
  printf("\n Enter the data:");
  scanf("%d", &y->data); 
  while (x->link != head)
  {
     x = x->link;
  } 
   x->link = y;
   y->link = head; 
   head = y;
}
void dequeue()
{
if (head == NULL) 
  printf("\n List is empty");
else
{
  x = head; 
  y = head;
}
while (x->link != head)
{
   x = x->link;
}
  head = y->link; 
  x->link = head; 
  free(y);
}
}
void display()
{
if (head == NULL) 
{
  printf("\n List is empty");
}
else
{
  x = head;
while (x->link != head)
{
 printf("%d",x->data);
 x=x->link;
}
printf("%d",x->data);
}
}
}
