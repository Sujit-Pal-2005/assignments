#include <stdio.h>
#include<stdlib.h>
#include <time.h>
//finding 
int pivort(int *arr,int p,int r,int *cmp){
    int x= arr[r];
    int i=p-1;
    int temp;
    for(int j=p;j<r;j++){
        if(arr[j]<=x){
            i=i+1;
            //swap
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
        (*cmp)++;
    }
    //swap
    arr[r]=arr[i+1];
    arr[i+1]=x;
    return i+1;
}

//Quick Sort
void quick_sort(int *arr,int p,int r,int *cmp){
    if(p<r){
        int q=pivort(arr,p,r,cmp);
        quick_sort(arr,p,q-1,cmp);
        quick_sort(arr,q+1,r,cmp);

    }
}
//Check for sorted
int isSorted(int *arr,int n){
    for (int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
srand(time(NULL));
    FILE *f=fopen("output.txt","w");
    for(int j=0;j<50000;j+=100){
        int n=j;
        int *arr=(int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++){
            arr[i]=rand()%10000;
        }
        int cnt=0;
        if(isSorted(arr,n)){
            printf("The array is already sorted\n");
        }
        else{
            quick_sort(arr,0,n-1,&cnt);
            if(isSorted(arr,n)){
               // printf("Now this is sorted\n");
               // printf("No of comparison for %d element is %d\n",n,cnt);
                fprintf(f,"%d %d\n",n,cnt);
            }
        }
        free(arr);
    }
    fclose(f);
    return 0;
}