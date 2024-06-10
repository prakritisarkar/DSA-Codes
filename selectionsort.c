#include<stdio.h>
void swap(int* a,int* b)
{
    int temp = *a;
    *a=*b;
    *b=temp;

}
void selectionsort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    { 
        int min=i;
        for(int j=i+1;j<n;j++)
        {
           if(arr[j]<arr[min])
           {
             min=j;
           }
           if(min!=i)
           {
            swap(&arr[i],&arr[min]);
           }
        }
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
    int data[]={1, 4,5,7,3,9,8 };
    int n=sizeof(data)/sizeof(data[0]);
    selectionsort(data,n);
    printf("sorted array in acesending order:\n");
    printarray(data,n);
    return 0;
}