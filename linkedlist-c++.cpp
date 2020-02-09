/*sample c++ program for explaining linked list*/
#include <iostream>
using namespace std;

class LinkedList {
    public:int a;
    public:LinkedList *next;
    public:void hello() {
        printf("%d\t",a);
    }
};

int main()
{
    LinkedList *p, *curr;
    p=new LinkedList();
    curr=p;
    p->a = 10;
    p->next=NULL;
    for(int i=2;i<=5;i++) {
        p->next = new LinkedList();
        int inn;
        scanf("%d",&inn);
        p->next->a = inn;
        p=p->next;
        p->next=NULL;
    }
    p=curr;
    while(p != NULL) {
        printf("%d\n", p->a);
        p=p->next;
    }
    return 0;
}