//stack-call by reference
#include<stdio.h>
#define max 5
void push(int[], int*);
void pop(int[], int*);
void display(int[], int*);
void peek(int[], int*);
void isempty(int[], int*);
void isfull(int[], int*);
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
                    printf("Stack is full");
                else
                    push(s, &top);
                break;
            case 2:
                if (top==-1)
                    printf("Stack is empty");
                else
                    pop(s, &top);
                break;
            case 3:
                if (top==-1)
                    printf("Stack is empty");
                else
                    display(s, &top);
                break;
            case 4:
                if (top==-1)
                    printf("Stack is empty");
                else
                    peek(s, &top);
                break;
            case 5:
                isempty(s, &top);
                break;
            case 6:
                isfull(s, &top);
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
void push(int s[], int *t)
{
    (*t)++;
    printf("Enter element in stack: ");
    scanf("%d", &s[*t]);
}
void pop(int s[], int *t)
{
    printf("Deleted Element: %d\n", s[*t]);
    (*t)--;
}
void display(int s[], int *t)
{
    int i;
    printf("Elements display: \n");
    for(i=*t; i>=0; i--)
        printf("%d\t", s[i]);
    printf("\n");
}
void peek(int s[], int *t)
{
    printf("Peek element: %d\n", s[*t]);
}
void isempty(int s[], int *t)
{
    if (*t==-1)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}
void isfull(int s[], int *t)
{
    if (*t==(max-1))
        printf("Stack is full\n");
    else
        printf("Stack is not full\n");
}