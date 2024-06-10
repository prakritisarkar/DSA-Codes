#include <stdio.h>
int linearsearch(int arr[], int n, int x) {
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == x)
    {
      return i;
    }
  }
        return -1;
}

int main() {
  int array[] = {2, 4, 0, 1, 9};
  int x = 4;
  int n = 5;

  int result = linearsearch(array, n, x);
  if(result==-1)
  {
    printf("element is not found");

  }
  else
  {
    printf("element is found at index:%d",result);
  }

  return 0;
}