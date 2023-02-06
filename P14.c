#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *left;
    int info;
    struct node *right;
} NODE;
NODE *insert(NODE *tree, int ele)
{
    if (tree==NULL)
    {
        tree=(NODE*)malloc(sizeof(NODE));
        tree->left=NULL;
        tree->info=ele;
        tree->right=NULL;
    }
    else if (ele>(tree->info))
        tree->right=insert(tree->right, ele);
    else
        tree->left=insert(tree->left, ele);
    return tree;
}
void inorder(NODE *tree)
{
    if(tree==NULL)
        return;
    inorder(tree->left);
    printf("%d\t", tree->info);
    inorder(tree->right);
}
void preorder(NODE *tree)
{
    if(tree==NULL)
        return;
    printf("%d\t", tree->info);
    preorder(tree->left);
    preorder(tree->right);
}
void postorder(NODE *tree)
{
    if(tree==NULL)
        return;
    postorder(tree->left);
    postorder(tree->right);
    printf("%d\t", tree->info);
}
void *minvalue(NODE* tree)
{
    NODE *ptr=tree;
    while ((ptr->left)!=NULL)
        ptr=ptr->left;
    printf("Minimum Value: %d\n", ptr->info);
}
void *maxvalue(NODE* tree)
{
    NODE *ptr=tree;
    while ((ptr->right)!=NULL)
        ptr=ptr->right;
    printf("Maximum Value: %d\n", ptr->info);
}
NODE* delete(NODE* tree, int ele)
{
    if (tree==NULL)
        return NULL;
    if (ele<tree->info)
        tree->left=delete(tree->left, ele);
    else if (ele>tree->info)
        tree->right=delete(tree->right, ele);
    else 
    {
        if (tree->left==NULL && tree->right==NULL)
            return NULL;
        else if (tree->left==NULL)
            return tree->right;
        else if (tree->right==NULL)
            return tree->left;
        else
        {
            NODE* p=NULL;
            for(p=tree; p->left!=NULL; p=p->right);
            tree->info=p->info;
            tree->right=delete(tree->right, tree->info);
        }   
    }
}
int main()
{
    NODE *tree=NULL;
    int x, ch;
    char y='Y';
    printf("1. Insert\n2. Inoreder\n3. Preorder\n4. Postorder\n5. Delete\n6. Minimum Value\n7. Maximum Value\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            {
                printf("Enter an element: ");
                scanf("%d", &x);
                tree=insert(tree, x);
                break;
            }
            case 2:
            {
                inorder(tree);
                printf("\n");
                break;
            }
            case 3:
            {
                preorder(tree);
                printf("\n");
                break;
            }
            case 4:
            {
                postorder(tree);
                printf("\n");
                break;
            }
            case 5:
            {
                printf("Enter an element: ");
                scanf("%d", &x);
                tree=delete(tree, x);
                break;
            }
            case 6:
            {
                minvalue(tree);
                break;
            }
            case 7:
            {
                maxvalue(tree);
                break;
            }
            default:
            {
                printf("Invalid entry\n");
                break;
            }
        }
        printf("Do you want to continue: ");
        scanf("%s", &y);
    } while (y=='Y' || y=='y');
    return 0;
}