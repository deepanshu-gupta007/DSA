//dubly linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *pre;
} NODE;
NODE* insertatbeg(NODE* start, int ele)
{
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    ptr->data=ele;
    ptr->pre=NULL;
    if (start==NULL)
        ptr->next=NULL;
    else
    {
        ptr->next=start;
        start->pre=ptr;
    }
    return ptr;
}
NODE* insertatend(NODE* start, int ele)
{
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    ptr->data=ele;
    ptr->next=NULL;
    if (start==NULL)
    {
        ptr->pre=NULL;
        return ptr;
    }
    else
    {
        NODE *t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=ptr;
        ptr->pre=t;
        return start;
    }
}
NODE* insertatpos(NODE* start, int n, int ele)
{
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    ptr->data=ele;
    if (start==NULL)
        return NULL;
    else if (n==1)
    {
        ptr->pre=NULL;
        ptr->next=start;
        start->pre=ptr;
        return ptr;
    }
    else
    {
        NODE *t=start;
        int i;
        for(i=1; i<n-1; i++)
            t=t->next;
        ptr->next=t->next;
        t->next->pre=ptr;
        t->next=ptr;
        ptr->pre=t;
        return start;
    }
}
NODE* deleteatbeg(NODE* start)
{
    if (start==NULL || start->next==NULL)
        return NULL;
    else
    {
        start=start->next;
        start->pre=NULL;
        return start;
    }
}
NODE* deleteatend(NODE* start)
{
    if (start==NULL || start->next==NULL)
        return NULL;
    else
    {
        NODE *t=start;
        while(t->next->next!=NULL)
            t=t->next;
        t->next=NULL;
        return start;
    }
}
NODE* deleteatpos(NODE* start, int n)
{
    if (start==NULL || n==1)
        return NULL;
    else
    {
        NODE *t=start;
        int i;
        for(i=1; i<n-1; i++)
            t=t->next;
        t->next=t->next->next;
        t->next->pre=t;
        return start;
    }
}
void traverse(NODE* start)
{
    if (start==NULL)
        printf("No data available\n");
    else
    {
        NODE *t=start;
        while(t->next!=NULL)
        {
            printf("%d\t", t->data);
            t=t->next;
        }
        printf("%d\n", t->data);
    }
}
int main()
{
    int ch, ele, n;
    char x='Y';
    printf("Menu:-\n1. Insert at beginning\n2. nsert at position\n3. Insert at end\n4. Delete from beginning\n5. Delete from postion\n6. Delete from end\n7. Traverse linked list\n8. Exit\n");
    NODE *start=NULL;
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            {
                printf("Enter number: ");
                scanf("%d", &ele);
                start=insertatbeg(start, ele);
                break;
            }
            case 2:
            {
                printf("Enter number and position:\n");
                scanf("%d %d", &ele, &n);
                start=insertatpos(start, n, ele);
                break;
            }
            case 3:
            {
                printf("Enter number: ");
                scanf("%d", &ele);
                start=insertatend(start, ele);
                break;
            }
            case 4:
            {
                start=deleteatbeg(start);
                break;
            }
            case 5:
            {
                printf("Enter position:\n");
                scanf("%d", &n);
                start=deleteatpos(start, n);
                break;
            }
            case 6:
            {
                start=deleteatend(start);
                break;
            }
            case 7:
            {
                traverse(start);
                break;
            }
            case 8:
            {
                x='N';
                break;
            }
            default:
            {
                printf("Invalid choice\n");
                break;
            }
        }
    } while (x=='Y');
    return 0;
}