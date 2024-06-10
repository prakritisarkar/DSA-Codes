#include<stdio.h>
void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int arr[],int lb,int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end;
}
void quicksort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
}
void printarray(int arr[],int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
int main()
{
    int data[]={5 , 4 , 3 , 1 , 0 , 10 , 6};
    int n=sizeof(data) / sizeof(data[0]);
    printf("unsorted array");
    printarray(data,n);
    quicksort(data,0,n-1);
    printf("sorted array in ascending order\n");
    printarray(data,n);
    return 0;
}