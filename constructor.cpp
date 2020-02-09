/* sample program to explain constructor */

#include <iostream>
using namespace std;
class A{
    private:
    int m;
    public:
    A *g;
    A() {
        this->m=1;
    }
    A(int a) {
        this->m = a;
    }
    
    A(A *t) {
        g=t;
    }
    
    int getM() {
        return this->m;
    }
};
int main()
{
    A c,b(10), s(&b);
    printf("%d,%d,%d\n",s.g->getM(),b.getM(),c.getM());

    return 0;
}