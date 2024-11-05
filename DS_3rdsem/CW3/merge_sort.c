#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//merging element
void merge(int *arr,int low ,int mid ,int high,int *cnt){
    int *temp=(int *)malloc((high-low+1)*sizeof(int));
    int j=0;
    int l=low,m=mid+1;
    while(l<=mid && m<=high ){
        if(arr[l]<=arr[m]){
            temp[j]=arr[l];
            j++;
            l++;
        }
        else{
            temp[j]=arr[m];
            j++;
            m++;
        }   
        (*cnt)++;
    }
    while(l<=mid ){
        temp[j]=arr[l];
        j++;
        l++;
        (*cnt)++;
    }
    while(m<=high){
        temp[j]=arr[m];
        j++;
        m++;
        (*cnt)++;
    }
    j=0;
    while(j<=high-low){
        arr[low+j]=temp[j];
        j++;
    }
    free(temp);
}
//divide
void merge_sort(int *arr,int low ,int high,int *cnt){
    int mid=low+(high-low)/2;
    if(low<high){
        merge_sort(arr,low,mid,cnt);
        merge_sort(arr,mid+1,high,cnt);
        merge(arr,low,mid,high,cnt);
    }
}
//check for sorted
int isSorted(int *arr,int n){
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            return 0;
        }
    }
    return 1;
}
//main function
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
            merge_sort(arr,0,n-1,&cnt);
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