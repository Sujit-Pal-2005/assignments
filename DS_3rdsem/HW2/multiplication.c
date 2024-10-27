#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int m,n;
    printf("Enter no of digits of first number:");
    scanf("%d",&m);
    printf("Enter first number :");
    char* s1=(char*)malloc(m);
     scanf("%s",s1);
    printf("Enter no of digits of second number::");
    scanf("%d",&n);
    printf("Enter second number :");
    char* s2=(char*)malloc(n);
    scanf("%s",s2);
    char * result =(char*)calloc((m+n+1),sizeof(char));
    for(int i=0;i<m+n;i++){
        result[i]='0';
    }
    for (int i = m - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = n - 1; j >= 0; j--) {
            int mul = (s1[i] - '0') * (s2[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = mul / 10;
            result[i + j + 1] = (mul % 10) + '0';
        }
        result[i] += carry;
    }
    for(int i=0;i<m+n+1;i++){
        if(result[i]!='0')break;
        result++;
    }
    printf("Multiplication result is :%s",result);
    free(s1);
    free(s2);
    free(result);

    return 0;
}
