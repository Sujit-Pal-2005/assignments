#include<stdio.h>
void majorityFinder(int arr[],int n){
     int flag=0;
    for(int i=0;i<=n/2;i++){
       int count=0;
       for(int j=i;j<n;j++){
            if(arr[i]==arr[j])count++;
       }
       if(count>n/2){
            printf("Majority element is : %d",arr[i]);
            flag++;
             break;
       }
    }
    if(flag ==0) printf("No majority element ");
  }
//optimal function
void majority(int arr[],int n){
    int el,count=0;
    for(int i=0;i<n;i++){
        if(count==0){
            el=arr[i];
            count=1;
        }
        else{
            if(el==arr[i])count++;
            else count--;
        }
    }    
     //another for loop to check this is majority
    count=0;
    for(int i=0;i<n;i++){
        if(el==arr[i])count++;
    }

    if(count>n/2){
        printf("Majority element is %d",el);
    }
    else{
        printf("No majority element");
    }
}

int main(){
    printf("Enter no of elements :");
    int n;
    scanf("%d",&n);
    printf("Enter elements :");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //brute force
    //majorityFinder(arr,n);

    //optimal
    majority(arr,n);

    return 0;
}