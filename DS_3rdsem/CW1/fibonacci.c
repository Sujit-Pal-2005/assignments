#include<stdio.h>
#include<stdlib.h>
//recursive code
int recfibonacci(int n,int arr[]){
    arr[n]++;
    if(n==0)return 0;
    if(n==1)return 1;
    return (recfibonacci(n-1,arr)+recfibonacci(n-2,arr));
}
//iterative code
int itrfibonacci(int n){
    int a=0,b=1,c=0;
    while(n--){
        a=b;
        b=c;
        c=a+b;
    }
    return c;
}

int main() {
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter 1 for iteration and any number without 1 for recursion:");
    int c;
    scanf("%d",&c);
    int *arr=(int*)calloc(n+1,sizeof(int));
    switch(c){
        case 1:printf("%d th fibonacci number by iteration is :%d\n",n,itrfibonacci(n));
            break;
        default:printf("%d th fibonacci number by recursion is :%d\n",n,recfibonacci(n,arr));
                int sum=0;
                for(int i=0;i<=n;i++){
                    sum+=arr[i];
                    printf("Fib(%d) is called:%d\n",i,arr[i]);
                }
                printf("Total recursion called :%d\n",sum);
    }
    return 0;
}
