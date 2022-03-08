#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shell_sort(int *arr, int n)
{
    int i, j, temp, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (j = gap; j < n; j++)
        {
            for (i=j-gap; i>=0 ; i = i - gap)
            if(arr[i+gap]>arr[i]){
                break;
            }
            else{
            temp=arr[i];
            arr[i]=arr[i+gap];
            arr[i+gap]=temp;
            }
        }
    }
}

int main()
{

    int arr[] = {8, 4, 2, 1, 7, 6, 5, 3};
    int n = 8;

    printArray(arr, n);
    shell_sort(arr, n);
    printArray(arr, n);

    return 0;
}