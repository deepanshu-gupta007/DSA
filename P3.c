//queue-call by value
#include<stdio.h>
#define max 5
int  f=-1, r=-1;
void enqueue(int[]);
void dequeue(int[]);
void display(int[]);
void peek(int[]);
void isempty(int[]);
void isfull(int[]);
int main() 
{
    int ch, s[max];
    char c;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Is Empty\n6. Is Full\n7. Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                enqueue(s);
                break;
            case 2:
                dequeue(s);
                break;
            case 3:
                display(s);
                break;
            case 4:
                peek(s);
                break;
            case 5:
                isempty(s);
                break;
            case 6:
                isfull(s);
                break;
            case 7:
                c='N';
                break;
            default:
                printf("Invalid Choice");
                break;
        }
        printf("Do you want to continue: ");
        scanf(" %c", &c);
    }while(c=='Y');
    return 0;
}
void enqueue(int s[])
{
    int ele;
    if(r==(max-1))
        printf("Queue is full\n");
    else
    {
        printf("Enter element in stack: ");
        scanf("%d", &ele);
        if (r==-1)
        {
            f=0, r=0;
            s[r]=ele;
        }
        else
        {
            r++;
            s[r]=ele;
        }
    }
}
void dequeue(int s[])
{
    int ele;
    if(f==-1)
        printf("Queue is empty\n");
    else
    {
        printf("Deleted Element = %d\n", s[f]);
        if (f==r)
            f=-1, r=-1;
        else
            f++;
    }
}
void display(int s[])
{
    int i;
    printf("Elements display: \n");
    for(i=f; i<=r; i++)
        printf("%d\t", s[i]);
    printf("\n");
}
void peek(int s[])
{
    printf("Peek element: %d\n", s[r]);
}
void isempty(int s[])
{
    if(f==-1)
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}
void isfull(int s[])
{
    if(r==(max-1))
        printf("Queue is full\n");
    else
        printf("Quue is not full\n");
}