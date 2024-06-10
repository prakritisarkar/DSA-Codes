#include<stdio.h>
int binarysearch(int arr[],int n,int data)
{
  int l=0,r=n-1;
  while(l<=r)
  {
   int mid=(l+r)/2;
   if(arr[mid]==data)
   {
    return mid;
   }
   else if(data<arr[mid])
   {
    r=mid-1;
   }
   else
   {
    l=mid+1;
   }
  }
  return -1;  
}
int main()
{
  int data,arr[7];
  printf("enter elements in a sorted way");
  
    for(int i=0;i<7;i++)
    {
      scanf("%d",&arr[i]);
    }
    printf("enter elements to be searched");
    scanf("%d",&data);
    int result = binarysearch(arr,7,data);
    if(result == -1)
    {
      printf("the elements is not found");
    }
    else
    {
      printf("the elements is found at index:%d",result);
    }
    return 0;
}