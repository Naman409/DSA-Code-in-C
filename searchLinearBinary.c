#include<stdio.h>

int linearSearch(int arr[],int size,int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}
// Binary Search can only be done for sorted array
int binarySearch(int arr[],int size,int element){
    int low,mid,high;
    low=0;
    high=size-1;

    while(low<=high){
    mid = (low+high)/2;
    if(arr[mid]==element){
        return mid;
    }
    if(arr[mid]<element){
        low = mid+1;
    }
    else{
        high = mid-1;
    }
    }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6};
    int sizeofarr = sizeof(arr)/sizeof(int);
    int element= 2;
    int searchIndex1 = linearSearch(arr,sizeofarr,element);
    int searchIndex2 = binarySearch(arr,sizeofarr,element);
    printf("We found your element %d at by linear search at index %d and by binary search at index %d",element,searchIndex1,searchIndex2);
}