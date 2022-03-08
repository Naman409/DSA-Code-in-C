#include<stdio.h>

void printArray(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void merge(int * arr,int low,int mid,int high){
    int i,j,k,new_arr[100];
    i=low;
    j=mid+1;
    k=low;

    while( i<=mid && j<=high ){
        if(arr[i]>arr[j]){
            new_arr[k]=arr[j];
            k++;j++;
        }else{
            new_arr[k]=arr[i];
            k++;i++;
        }
    }
    while(i<=mid){
        new_arr[k]=arr[i];
        k++;i++;
    }
    while(j<=high){
        new_arr[k]=arr[j];
        k++;j++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=new_arr[i];
    }

}

void merge_sort(int * arr,int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);

    }
}

int main(){
    int arr[]={8,4,2,1,7,6,5,3};
    int n=8;

    printArray(arr,n);
    merge_sort(arr,0,7);
    printArray(arr,n);

    return 0;
}