#include <iostream>
#include <cstring>
using namespace std;

class String {
    private:
    char *s;
    public:
    char* getString() {
        return (this->s);
    }
    char* getString(char* h) {
        char *t;
        t=new char[std::strlen(this->s)+std::strlen(h)];
        std::strcat(t,h);
        std::strcat(t,this->s);
        return t;
    }
    void setString(char* p) {
        this->s = p;
    }
    
    void setString(char p) {
        char *temp;
        temp=new char();
        for(int m=0;m<5;m++) {
            *(temp+m) = p;
        }
        this->s = temp;
    }
    
};
int main()
{   
    
    String h;
    h.setString("hello");
    printf("%s\n",h.getString("prince"));
    return 0;
}