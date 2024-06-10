#include <stdio.h> 
#define size 50 
struct stack 
{ 
    int arr[size]; 
    int tos; 
};
struct stack st; 
void init() 
{ 
    st.tos=-1; 
} 
int isfull() 
{ 
    if (st.tos==size-1) 
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
    if (st.tos==-1) 
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
    if (isfull()) 
    { 
        return; 
    } 
    else 
    { 
        st.tos++; 
        st.arr[st.tos]=n; 
         
    } 
} 
int pop() 
{ 
    int temp; 
    if (isempty()) 
    { 
        return -9999; 
    } 
    else 
    {    
        temp=st.arr[st.tos]; 
        st.tos--; 
        return temp; 
    } 
} 
int peek() 
{ 
     
    if (isempty()==1) 
    { 
        return -9999; 
    } 
    else 
    { 
        return st.arr[st.tos];  
    } 
} 
int prcd(char ch) 
{ 
    if (ch=='^') 
        return 4; 
    else if (ch=='*'|| ch=='/'|| ch=='%') 
        return 3; 
    else if (ch=='+' || ch=='-') 
        return 2; 
    else 
        return 1; 
} 
int main()
{
    
    char a[size],b[size];
    int i,j,r;
    printf("enter the infix expression");
    scanf("%s",&a);
    for(i=0,j=0;a[i]!='\0';++i)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            b[j++]=a[i];
        }
        else
        {
            if(a[i]=='(')
            {
                push(a[i]);
            }
            else if (a[i]==')')
            {
              do
              {
                r=pop();
                if(r!='(')
                {
                    b[j++]=r;
                }
              } while (r!='(');
              
            }
            else
            {
                while(isempty()==0 &&( prcd(peek())>=prcd(a[i])))
                {
                    b[j++]=pop();
                }
                push(a[i]);
            }
            
        }
    }
    while(isempty()==0)
    {
        b[j++]=pop();
    }
    b[j]='\0';
    printf("%s\n",b);
    init();
    for(int k=0;b[k]!='\0';++k)
    {
        if(b[k]>='0' && b[k]<='9')
        {
           push(b[k]-'0');
        }
        else
        {
           int x=pop();
           int y=pop();
           if(b[k]=='+')
           push(x+y);
           else if(b[k]=='-')
           push(y-x);
           else if(b[k]=='*')
           push(x*y);
           else if(b[k]=='/')
           push(y/x);
        }
    }
   int result=pop();
   printf("%d\n",result);
   return 0;

}