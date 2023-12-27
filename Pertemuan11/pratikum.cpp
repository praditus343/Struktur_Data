#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};
// Create a new Node
BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert data into BST
BstNode* Insert(BstNode* root, int data) {
    if (root == NULL) { // empty tree
        root = GetNewNode(data);
    } else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}

// Search element in BST
bool Search(BstNode* root, int data) {
    if (root == NULL) {
        return false;
    } else if (root->data == data) {
        return true;
    } else if (data <= root->data) {
        return Search(root->left, data);
    } else {
        return Search(root->right, data);
    }
}

//Traverse
void printInorder(BstNode* root)
{
	if (root == NULL)
	return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}
int main() {
	cout<<"\t==BINARY SEARCH TREE==\n\n";
	BstNode* root = NULL;
	
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	
	print("Urutan Data Tree secara Inorder");
	print("\n===================================\n");
	printInorder(root);
	
	int number;
	cout<<"\n\nMasukkan nomor yang dicari : ";
	cin>>number;
	
	if(Search(root,number) == true) cout<<"\nData ditemukan\n";
	else cout<<"Data Tidak Ditemukan\n";	
}