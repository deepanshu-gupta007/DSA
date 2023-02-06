//circular queue-call by reference
#include<stdio.h>
#define max 5
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
                if ((r+1)%max==f)
                    printf("Queue is full\n");
                else
                {
                    enqueue(s, &f, &r);
                    if (f==-1)
                        f=0;
                }
                break;
            case 2:
                if(f==-1 && r==-1)
                    printf("Queue is empty\n");
                else
                {
                    dequeue(s, &f, &r);
                    if (f==r)
                        r=-1;
                }
                break;
            case 3:
                if(f==-1 && r==-1)
                    printf("Queue is empty\n");
                else
                    display(s, &f, &r);
                break;
            case 4:
                if(f==-1 && r==-1)
                    printf("Queue is empty\n");
                else
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
    *r=(*r+1)%max;
    printf("Enter element in stack: ");
    scanf("%d", &s[*r]);
}
void dequeue(int s[], int *f, int *r)
{
    printf("Deleted Element = %d\n", s[*f]);
    if (*f==*r)
        *f=-1;
    else
        *f=(*f+1)%max;;
}
void display(int s[], int *f, int *r)
{
    printf("Elements display: \n");
    while(*f!=*r)
    {
        printf("%d\t", s[*f]);
        *f=(*f+1)%max;
    }
    printf("%d\t", s[*f]);
    printf("\n");
}
void peek(int s[], int *f, int *r)
{
    printf("Peek element: %d\n", s[*r]);
}
void isempty(int s[], int *f, int *r)
{
    if(*f==-1 && *r==-1)
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}
void isfull(int s[], int *f, int *r)
{
    if((*r+1)%max==*f)
        printf("Queue is full\n");
    else
        printf("QuEue is not full\n");
}