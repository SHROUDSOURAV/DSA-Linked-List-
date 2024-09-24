#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
}node;
node *Create(int data)//function to allocate memory for node creation
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}
void Insert(node *root,int data)//function to insert node as per BST standard(left < root and right > root)
{
    if(data < root->data)
    {
        if(root->left == NULL)
            root->left = Create(data);
        else
            Insert(root->left,data);
    }
    else if(data > root->data)
    {
        if(root->right == NULL)
            root->right = Create(data);
        else
            Insert(root->right,data);
    }
    else printf("Duplicate Values not Allowed!!!\n");
}
void Preorder(node *root)//function for preorder traversal
{
    if(root == NULL)
        return;
    else
    {
        printf("%d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
void Inorder(node *root)//function for inorder traversal
{
    if(root == NULL)
        return;
    else
    {
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}
void Postorder(node *root)//function for postorder traversal
{
    if(root == NULL)
        return;
    else
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    int a;//switch variable
    char ch;//loop variable
    int data;//data to insert in node variable
    node *root = NULL;//root node
    do
    {
        printf("1.Insert Node\n");
        printf("2.Preorder Traversal\n");
        printf("3.Inorder Traversal\n");
        printf("4.Postorder Traversal\n");
        printf("Enter your choice : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                printf("Enter the data : ");
                scanf("%d",&data);
                if(root == NULL)
                    root = Create(data);
                else
                    Insert(root,data);
                break;
                case 2:
                    Preorder(root);
                    break;
                case 3:
                    Inorder(root);
                    break;
                case 4:
                    Postorder(root);
                    break;
            default:
                printf("INVALID CHOICE!!!\n");
        }
        printf("\nDo you want to Continue(Y/N): ");
        scanf(" %c",&ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}