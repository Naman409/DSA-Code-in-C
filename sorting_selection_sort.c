#include<stdio.h>

void printArray(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void selection_sort(int * arr,int n){
    int indexofminimum,temp;
    for(int i=0;i<n-1;i++){
        indexofminimum = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[indexofminimum]){
                indexofminimum=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[indexofminimum];
        arr[indexofminimum]=temp;

    }
}

int main(){
    int arr[5]={50,20,40,30,10};
    int n=5;

    printArray(arr,n);
    selection_sort(arr,n);
    printArray(arr,n);

    return 0;
}