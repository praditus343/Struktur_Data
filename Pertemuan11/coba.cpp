#include <iostream>
using namespace std;

// Definition of Node for Binary Search Tree
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

// Find the smallest element in BST
int first(BstNode* root) {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return -1;
    } else if (root->left == NULL) {
        return root->data;
    }
    return first(root->left);
}

// Find the largest element in BST
int last(BstNode* root) {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return -1;
    } else if (root->right == NULL) {
        return root->data;
    }
    return last(root->right);
}

// Print BST in inorder
void printInorder(BstNode* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    BstNode* root = NULL;
    
    
    
    printf("\n");
    printf("Nama    : Praditus Egi Danuarta\n");
    printf("Nim     : 22.11.4662\n");

    // Insert nodes into the tree
    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 20);
    root = Insert(root, 2);
    root = Insert(root, 6);
    root = Insert(root, 19);
    root = Insert(root, 25);
    root = Insert(root, 21);

    int choice;
    while (true) {
        cout << "\nMENU:\n";
        cout << "1. Tambahkan Node\n";
        cout << "2. Nilai Terkecil\n";
        cout << "3. Nilai Terbesar\n";
        cout << "4. Cari Elemen\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Terima kasih. Program selesai.\n";
                return 0;
            case 1: {
                int value;
                cout << "Masukkan nilai node baru: ";
                cin >> value;
                root = Insert(root, value);
                cout << "Node berhasil ditambahkan.\n";
                break;
            }
            case 2: {
                int minValue = first(root);
                if (minValue != -1) {
                    cout << "Nilai terkecil: " << minValue << endl;
                }
                break;
            }
            case 3: {
                int maxValue = last(root);
                if (maxValue != -1) {
                    cout << "Nilai terbesar: " << maxValue << endl;
                }
                break;
            }
            case 4: {
                int searchValue;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> searchValue;
                if (Search(root, searchValue)) {
                    cout << "Data ditemukan.\n";
                } else {
                    cout << "Data tidak ditemukan.\n";
                }
                break;
            }
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
        cout << "\nUrutan Data Tree secara Inorder\n";
        cout << "===============================\n";
        printInorder(root);
        cout << endl;
    }

    return 0;
}