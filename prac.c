#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximum(int * arr,int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i+1]>max){
            max=arr[i+1];
        }
    }
    return max;
}

void counting_sort(int * arr,int n){
    int * count,i,max;
    max=maximum(arr,n);
    count=(int *)malloc(sizeof(int)*(max+1));
    for(i=0;i<max+1;i++){
        count[i]=0;
    }
    for(i=0;i<n;i++){
        count[arr[i]]=count[arr[i]]+1;
    }
    for(i=0;i<max+1;i++){
        printf("%d ",count[i]);
    }
}

int main(){
    int n;
    scanf("%d\n",&n);
    int *arr;
    arr = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    counting_sort(arr,n);
    return 0;
}