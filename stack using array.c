#include<stdio.h>
#define Size 10
struct stack
{
    int arr[Size];
    int tos;
    };
    struct stack st;
    void init()
    {
        st.tos=-1;
    }
    int isfull()
    {
     if (st.tos==Size-1)
      {
       return 1;
      }

      else
      {
         return 0;
      }
    }
    int isempty()
    {
      if(st.tos==-1)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
    void push(int n)
    {
        if(isfull())
        return;
        else
        st.tos++;
        st.arr[st.tos]=n;
    }
    int pop()
    {
        if(isempty())
        return -9999;
        else
        { 
       int temp=st.arr[st.tos];
       st.tos--;
       return temp;
        }
    }
    int peek()
    {
      if(st.tos==-1)
      {
        return-9999;
      }
      else{
        return st.arr[st.tos];
      }
    }
    int main()
    {
      init();
      int ch,r,tos;
      int n;
      printf("\nmain menu\n.....\n1.push an element.\n2.pop of an element.\n3.peek the top of the stack.\n4.exit 0 to \n");
       do
       {
         printf("enter your choice");
         scanf("%d",&ch);
         switch(ch)
         {
          case 1:
          printf("enter the element to be stored",n);
          scanf("%d",&n);
          push(n);
          break;
          case 2:
          r=pop();
          if(r!=-9999)
          printf("%d is popped out of the stack",r);
          else
          {
            printf("stack is empty");
          }
          break;
          case 3:
          tos=peek();
          printf("%d is the top of the stack",tos);
          break;
          case 4:
          printf("exit");
          break;
          default:
          printf("invalid choice");

         }
       }
       while(ch!=0);   
    }