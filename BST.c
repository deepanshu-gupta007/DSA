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
int count_nodes(NODE *tree)
{
    if(tree==NULL)
        return 0;
    else
        return 1+count_nodes(tree->left)+count_nodes(tree->right);
}
int count_leaf_nodes(NODE *tree)
{
    if(tree==NULL)
        return 0;
    else if ((tree->left)==NULL && (tree->right)==NULL)
        return 1;
    else
        return count_leaf_nodes(tree->left)+count_leaf_nodes(tree->right);
}
int count_one_child_nodes(NODE *tree)
{
    if(tree==NULL)
        return 0;
    else if (((tree->left)==NULL && (tree->right)!=NULL)||((tree->left)!=NULL && (tree->right)==NULL))
        return 1;
    else
        return count_one_child_nodes(tree->left)+count_one_child_nodes(tree->right);
}
int main()
{
    NODE *tree=NULL;
    int x, total_nodes, total_leaf_nodes, total_one_child_nodes;
    char y='Y';
    do
    {
        printf("Enter an element: ");
        scanf("%d", &x);
        tree=insert(tree, x);
        printf("Do you want to enter more elements: ");
        scanf("%s", &y);
    } while (y=='Y' || y=='y');
    total_nodes=count_nodes(tree);
    printf("Total number of nodes: %d\n", total_nodes);
    total_leaf_nodes=count_leaf_nodes(tree);
    printf("Total number of leaf nodes: %d\n", total_leaf_nodes);
    total_one_child_nodes=count_one_child_nodes(tree);
    printf("Total number of one child nodes: %d\n", total_one_child_nodes);
    return 0;
}