//queue-call by reference
#include<stdio.h>
#define max 3
void enqueue(int[], int*, int*);
void dequeue(int[], int*, int*);
void display(int[], int*, int*);
void peek(int[], int*, int*);
void isempty(int[], int*, int*);
void isfull(int[], int*, int*);
int main() 
{
    int ch, s[max], f=-1, r=-1;
    char c;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Is Empty\n6. Is Full\n7. Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                enqueue(s, &f, &r);
                break;
            case 2:
                dequeue(s, &f, &r);
                break;
            case 3:
                display(s, &f, &r);
                break;
            case 4:
                peek(s, &f, &r);
                break;
            case 5:
                isempty(s, &f, &r);
                break;
            case 6:
                isfull(s, &f, &r);
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
void enqueue(int s[], int *f, int *r)
{
    int ele;
    if(*r==(max-1))
        printf("Queue is full\n");
    else
    {
        printf("Enter element in stack: ");
        scanf("%d", &ele);
        if (*r==-1)
        {
            *f=0, *r=0;
            s[*r]=ele;
        }
        else
        {
            (*r)++;
            s[*r]=ele;
        }
    }
}
void dequeue(int s[], int *f, int *r)
{
    int ele;
    if(*f==-1)
        printf("Queue is empty\n");
    else
    {
        printf("Deleted Element = %d\n", s[*f]);
        if ((*f)==(*r))
            *f=-1, *r=-1;
        else
            (*f)++;
    }
}
void display(int s[], int *f, int *r)
{
    int i;
    printf("Elements display: \n");
    for(i=*f; i<=*r; i++)
        printf("%d\t", s[i]);
    printf("\n");
}
void peek(int s[], int *f, int *r)
{
    printf("Peek element: %d\n", s[*r]);
}
void isempty(int s[], int *f, int *r)
{
    if((*f)==-1)
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}
void isfull(int s[], int *f, int *r)
{
    if(*r==(max-1))
        printf("Queue is full\n");
    else
        printf("Quue is not full\n");
}