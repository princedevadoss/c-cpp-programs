#include <iostream>
using namespace std;

class M {
    private:
    int m;
    public:
    int getM() {
        return this->m;
    }
    void setM(int m) {
        this->m = m;
    }
};
int main()
{
    M m1;
    m1.setM(20);
    printf("%d\n",m1.getM());

    return 0;
}