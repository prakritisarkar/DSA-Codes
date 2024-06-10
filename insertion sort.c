#include<stdio.h>
void insertionsort(int arr[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>= 0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
int main()
{
    int data[]={4,6,8,3,9,2,0};
    int n=sizeof(data) /sizeof(data[0]);
    insertionsort(data,n);
    printf("sorted array in ascending order:\n");
    printarray(data,n);
    return 0;  
}