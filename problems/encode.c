#include<stdio.h>
#include<string.h>
void encode(char *str,int len){
    for(int i = 0; i < len ;i++) {

		int count = 1;
		while(str[i] == str[i+1]) {
		i++;
		count++;
		}
		printf("%c%d",str[i],count);
	}
}
void main()
{
	char str[100],len;
	printf("Enter the string: "); 
     scanf("%[^\n]%*c", str);
    len =  strlen(str);
    encode(str,len);
}