#include <stdio.h> 
#define MS 15 
struct queue 
{ 
    int a[MS]; 
    int r; 
}q; 
void init() 
{ 
    q.r=-1; 
} 
int isfull() 
{ 
    return q.r==MS-1; 
} 
int isempty() 
{ 
    return q.r==-1; 
} 
void enqueue(int val) 
{ 
    int c,p,t; 
    if (isfull()) 
        printf("ERROR:Queue is full!No more elements can be inserted.\n"); 
    else 
    { 
        q.r=q.r+1; 
        q.a[q.r]=val; 
        c=q.r; 
        while(c>0) 
        { 
            p=(c-1)/2; 
            if (q.a[p]<q.a[c]) 
            { 
                t=q.a[p]; 
                q.a[p]=q.a[c]; 
                q.a[c]=t; 
                c=p; 
            } 
            else 
                break; 
        } 
        printf("%d is inserted in thq queue.\n",val); 
    } 
} 
int dequeue() 
{ 
    int p,c,t; 
    if (isempty()) 
        return -999; 
    else 
    { 
        int z=q.a[0]; 
        q.a[0]=q.a[q.r]; 
        q.r=q.r-1; 
        p=0; 
        do 
        { 
            c=2*p+1; 
            if (c>q.r) 
               break; 
            else 
            { 
                if ((c<q.r) && (q.a[c]<q.a[c+1])) 
                   c=c+1; 
                if (q.a[p]<q.a[c]) 
                { 
                    int t=q.a[p]; 
                    q.a[p]=q.a[c]; 
                    q.a[c]=t; 
                    p=c; 
                } 
                else 
                    break; 
            } 
        } while (c<=q.r); 
        return z; 
    } 
} 
int main() 
{ 
    init(); 
    printf("MAIN MENU\n_\n1.Insert an element\n2.Delete an element\n3.Exit\n"); 
    int ch,x,r; 
    do 
    { 
        printf("Enter your choice:"); 
        scanf("%d",&ch); 
        switch (ch) 
        { 
            case 1: 
               printf("Enter the element to be inserted:"); 
               scanf("%d",&x); 
               enqueue(x); 
               break; 
            case 2: 
               r=dequeue(); 
               if (r==-999) 
               { 
                   printf("ERROR:The queue is empty.\n"); 
               } 
               else 
               { 
                   printf("%d is being deleted from the queue.\n",r); 
               } 
               break; 
            case 3: 
               printf("Exit\n"); 
               break; 
            default: 
               printf("ERROR:Please enter the correct choice.\n"); 
                
        } 
    } while (ch!=3); 
     
}