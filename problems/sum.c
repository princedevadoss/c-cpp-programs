#include<stdio.h>
int main()
{
int i,x[7],sum=0;
printf("enter the elements:");
for(i=0;i<7;i++)
 {
  scanf("%d",x+i);
  sum=*(x+i);
 }
 printf("sum=%d",sum);
 return 0;
}