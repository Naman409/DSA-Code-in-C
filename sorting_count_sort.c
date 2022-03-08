#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int maximum(int * arr,int n){
    int max=arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

void count_sort(int * arr,int n){
    int i,j,max,*count;
    max=maximum(arr,n);
    count = (int *)malloc(sizeof(int)*(max+1));

    for(i=0;i<max+1;i++){
        count[i]=0;
    }

    for(i=0;i<n;i++){
        count[arr[i]]=count[arr[i]]+1;
    }
    i=0;
    j=0;

    while(i<=max){
        if(count[i]>0){
            arr[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else{
            i++;
        }
    }

}

int main(){

    int arr[]={8,4,2,1,7,6,5,3};
    int n=8;

    printArray(arr,n);
    count_sort(arr,n);
    printArray(arr,n);

    return 0;
}