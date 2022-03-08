#include<stdio.h>

void printArray(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubble_sort(int *arr,int n){
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        printf("Working on pass %d\n",i+1);
        for(int j=0;j<n-1-i;j++){
        if(arr[j]>arr[j+1]){
            temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
    }
    
}

void bubble_sort_adaptive(int *arr,int n){
    int temp;
    int isSorted =0;
    for (int i = 0; i < n-1; i++)
    {
        isSorted=1;
        printf("Working on pass %d\n",i+1);
        for(int j=0;j<n-1-i;j++){
        if(arr[j]>arr[j+1]){
            temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
    
}


int main(){
    int arr[]={20,40,10,30,60,50};
    int n=6;
    printArray(arr,n);
    // bubble_sort_adaptive(arr,n);
    bubble_sort(arr,n);
    printArray(arr,n);
    return 0;
}
