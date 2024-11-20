#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int isSorted(int *arr, int n){
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i-1]) return 0;
    }
    return 1;
}

int main()
{
    srand(time(NULL));
    int n;
    printf("Enter number of element: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
        arr[i]=(rand() % 100000)+1;
    }
    //checking the array
    if(isSorted(arr,n)){
        printf("It is sorted");
    }
    else {
        printf("It is not sorted\n");
    }
    int comp = 0;
    for(int i = 1; i < n; i++){
        int j = i-1;
        int temp=arr[i];
        while(j>=0&& temp< arr[j]){
            arr[j+1] = arr[j];
            comp++;
            j--;
        }
        arr[j+1]=temp;
    }
    printf("Number of comparisons: %d\n", comp);

    if(isSorted(arr,n))printf("Now it is sorted\n");
    
    // for(int i=0;i<n;i++){
    //     printf("%d ",arr[i]);
    //  }
    return 0;
}
