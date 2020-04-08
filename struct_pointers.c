#include <stdio.h>

struct student {
    char name[100];
    int rollno;
    float lang1;
    float lang2;
};

int main() {
    struct student z[20];
    for(int i=0; i<20; i++) {
        scanf("%s", &z[i].name);
        scanf("%d", &z[i].rollno);
        scanf("%f", &z[i].lang1);
        scanf("%f", &z[i].lang2);
        printf("%s, %d, %f, %f\n", z[i].name, z[i].rollno, z[i].lang1, z[i].lang2);
    }
    return 0;
}