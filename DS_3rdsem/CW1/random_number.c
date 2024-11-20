#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int n,low,high;
    printf("Enter n:");
    scanf("%d",&n);

    printf("Enter low and high range :");
    scanf("%d %d",&low,&high);
    
    srand(time(NULL));
    printf("Random numbers are : ");
    while(n--){
        int x=low+(rand()%(high-low+1));
        printf("%d ",x);
    }
    return 0;
}
