#include<stdio.h>
void bubblesort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
    int flag=0;
    for(int j=0;j<n-1-i;j++)
    {
        if(arr[j]>arr[j+1])
        {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            flag= 1;
        }
    }
    if(flag==0)
     {
        break;
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
    int data[]={-2, 55,0,13,-3};
      int n=sizeof(data) / sizeof(data[0]);
      bubblesort(data,n);
      printf("sorted array in ascending order:\n");
      printarray(data,n);
      return 0;
}