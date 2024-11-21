#include <stdio.h>
#include<stdlib.h>
#include <time.h>

typedef long unsigned int l;
//for insertion sort
void insertion_sort(int * arr,int n,l *cnt){
    for(int i = 1; i < n; i++){
        int j = i-1;
        int temp=arr[i];
        while(j>=0&& temp< arr[j]){
            arr[j+1] = arr[j];
            (*cnt )++;
            j--;
        }
        arr[j+1]=temp;
    }
}

//For merge sort
//merging element
void merge(int *arr,int low ,int mid ,int high,l *cnt){
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
void merge_sort(int *arr,int low ,int high,l *cnt){
    int mid=low+(high-low)/2;
    if(low<high){
        merge_sort(arr,low,mid,cnt);
        merge_sort(arr,mid+1,high,cnt);
        merge(arr,low,mid,high,cnt);
    }
}

//For quick sort
//finding pivort
int pivort(int *arr,int p,int r,l *cmp){
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
void quick_sort(int *arr,int p,int r,l *cmp){
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
    FILE *f=fopen("output2.txt","w");
    for(int j=100;j<=30000;j+=100){
        int n=j;
        int *arr=(int*)malloc(n*sizeof(int));
        //Insertion sort
        for(int i=0;i<n;i++){
            arr[i]=rand()%10000;
        }
        l cnt=0;
        if(isSorted(arr,n)){
            printf("The array is already sorted\n");
        }
        else{
            insertion_sort(arr,n,&cnt);
            if(isSorted(arr,n)){
                fprintf(f,"%d %ld %d\n",n,cnt,0);
            }
        }
        //merge sort
        for(int i=0;i<n;i++){
            arr[i]=rand()%10000;
        }
        cnt=0;
        if(isSorted(arr,n)){
            printf("The array is already sorted\n");
        }
        else{
            merge_sort(arr,0,n-1,&cnt);
            if(isSorted(arr,n)){
                fprintf(f,"%d %ld %d\n",n,cnt,1);
            }
        }
        //quick sort
        for(int i=0;i<n;i++){
            arr[i]=rand()%10000;
        }
        cnt=0;
        if(isSorted(arr,n)){
            printf("The array is already sorted\n");
        }
        else{
            quick_sort(arr,0,n-1,&cnt);
            if(isSorted(arr,n)){
                fprintf(f,"%d %ld %d\n",n,cnt,2);
            }
        }
        free(arr);
    }
    fclose(f);
    return 0;
}