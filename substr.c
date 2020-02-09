/*
    Find Whether substring is present inside given string.
*/
#include <stdio.h>
int main()
{
    char s[]="aaat" , ss[]="at";
    int j = 0;
    
    for(int m=0;m<4;m++) {
        for(int n=0;n<2;n++) {
            if(ss[n]==s[m]){
                if(n==1) {
                    j=1;
                    break;                                                          
                }
                if(m<4){
                    m++;
                }
            }
            else {
                break;
            }
        }
        if(j==1) {
            break;
        }
    }
    printf("%d\n", j);

    return 0;
}