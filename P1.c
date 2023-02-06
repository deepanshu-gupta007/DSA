//stack-call by value
#include<stdio.h>
#define max 5
int push(int[], int);
int pop(int[], int);
void display(int[], int);
void peek(int[], int);
void isempty(int[], int);
void isfull(int[], int);
int main() 
{
    int ch, s[max], top=-1;
    char c;
    printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Is Empty\n6. Is Full\n7. Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                if (top==(max-1))
                    printf("Stack is full\n");
                else
                    top=push(s, top);
                break;
            case 2:
                if (top==-1)
                    printf("Stack is empty\n");
                else
                    top=pop(s, top);
                break;
            case 3:
                if (top==-1)
                    printf("Stack is empty\n");
                else
                    display(s, top);
                break;
            case 4:
                if (top==-1)
                    printf("Stack is empty\n");
                else
                    peek(s, top);
                break;
            case 5:
                isempty(s, top);
                break;
            case 6:
                isfull(s, top);
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
int push(int s[], int top)
{
    top++;
    printf("Enter element in stack: ");
    scanf("%d", &s[top]);
    return top;
}
int pop(int s[], int top)
{
    printf("Deleted Element: %d\n", s[top]);
    top--;
    return top;
}
void display(int s[], int top)
{
    int i;
    printf("Elements display: \n");
    for(i=top; i>=0; i--)
        printf("%d\t", s[i]);
    printf("\n");
}
void peek(int s[], int top)
{
    printf("Peek element: %d\n", s[top]);
}
void isempty(int s[], int top)
{
    if (top==-1)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}
void isfull(int s[], int top)
{
    if (top==(max-1))
        printf("Stack is full\n");
    else
        printf("Stack is not full\n");
}