/* =============================
 == PROGRAM BINARY TREE==
 =============================*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node* left;
    struct node* right;
};

struct node* newNode(char data)
{
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}
void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
    printf("%c ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%c ", node->data);
    printInorder(node->right);
}

void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%c ", node->data);
}
int main()
{
    struct node* root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->right = newNode('D');
    root->right->left = newNode('E');
    root->right->right = newNode('F');
    root->left->right->left = newNode('G');
    root->right->left->right = newNode('H');

    printf("\n");
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
