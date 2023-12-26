#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct node* insert(struct node* node, int data)
{
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main()
{
    struct node* root = NULL;
    
    int data[] = {20, 10, 28, 6, 15, 35, 8, 2, 7, 40, 12, 9, 25};
    int dataSize = sizeof(data) / sizeof(data[0]);
    
    for (int i = 0; i < dataSize; i++) {
        root = insert(root, data[i]);
    }

    printf("Nama    : Praditus Egi Danuarta\n");
    printf("Nim     : 22.11.4662\n");

    printf("\n== TRAVERSAL PADA BINARY TREE ==\n");

    printf("\nKunjungan Preorder:\n");
    printf("====================\n");
    printPreorder(root);
    printf("\n");

    printf("\nKunjungan Inorder:\n");
    printf("====================\n");
    printInorder(root);
    printf("\n");

    printf("\nKunjungan Postorder:\n");
    printf("====================\n");
    printPostorder(root);
   
    getchar();
    return 0;
}
