// Binary Search Tree
// Program sederhana untuk membuat BST dan mencari elemen di dalamnya
#include <iostream>
using namespace std;
// Definisi Node untuk pohin pencarian Biner
struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

// membuat Node baru
BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Memasukkan data ke BST
BstNode* Insert(BstNode* root, int data){
    if(root == NULL){
        root = GetNewNode(data);
    }
    // jika data yang akan disisipkan lebih sedikit, sisipkan di subpohon kiri
    else if(data <= root->data){
        root->left = Insert(root->left,data);
    }
    // lainnya, masukkan di subpohon kanan
    else{
        root->right = Insert(root->right,data);
    }
    return root;
}

// Pencarian element di BST
bool Search(BstNode* root, int data){
    if(root == NULL){
        return false;
    }
    else if(root->data == data){
        return true;
    }
    else if(data <= root->data){
        return Search(root->left,data);
    }
    else{
        return Search(root->right, data);
    }
}

// Pencarian data terkecil
int first(BstNode* root){
    if(root == NULL){
        cout<<"TREE KOSONG!!"<< endl;
    }else if(root->left == NULL){
        return root->data;
    }
    return first(root->left);
}

int last(BstNode* root){
    if(root == NULL){
        cout<<"TREE KOSONG!!"<< endl;
    }else if(root->right == NULL){
        return root->data;
    }
    return last(root->right);
}

// Traverse
void printPostorder(BstNode* root){
    if(root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data <<" ";
}

int main(){
    int pilihMenu, inputData, number;
    
    BstNode* root = NULL; // membuat tree kosong
    /*Penambahan node pada tree*/
    root = Insert(root,10);
    root = Insert(root,5);
    root = Insert(root,20);
    root = Insert(root,2);
    root = Insert(root,6);
    root = Insert(root,19);
    root = Insert(root,25);
    root = Insert(root,21);    
    // menu
    menu:
    cout<<"Nama\t: Praditus Egi Danuarta\nNIM\t: 22.11.4662\n\n";
    cout <<"\t== BINARY SEARCH TREE==";
    cout<<"\n1. Penambahan Node"<< endl;
    cout<<"2. Data Terkecil PostOrder"<< endl;
    cout<<"3. Data Terbesar PostOrder"<< endl;
    cout<<"4. Pencarian Data"<< endl;
    cout<<"5. Urutan Data PostOrder\n";
    cout<<"Pilih : ";
    cin>>pilihMenu;  
    switch(pilihMenu){
        case 1:
            cout <<"\nTambahkan data : ";
            cin>>inputData;
            root = Insert(root,inputData);
            cout<<"Data berhasil ditambahkan"<< endl;
            system("pause");
            system("cls");
            goto menu;            
        case 2:
            cout<< endl;
            cout<<"Urutan Data Tree secara PostOrder"<< endl;
            cout<<"==============================="<< endl;
            printPostorder(root);
            cout <<"\n\nMencari Nilai Terkecil" << endl;
            cout <<"\nNilai Terkecil : " << first(root);
            cout<< endl;
            system("pause");
            system("cls");
            goto menu;       
        case 3:
            cout<< endl;
            cout<<"Urutan Data Tree secara PostOrder"<< endl;
            cout<<"==============================="<< endl;
            printPostorder(root);
            cout <<"\n\nMencari Nilai Terbesar" << endl;
            cout <<"\nNilai Terbesar : " << last(root);
            cout<< endl;
            system("pause");
            system("cls");
            goto menu;     
        case 4:
            cout<< endl;
            printPostorder(root);
            cout<< "\n\nMasukkan nomor yang dicari : ";
            cin>> number;
            //menampilkan hasil pencarian
            if(Search(root,number) == true) cout<< "\nData " << number << " ditemukan\n";
            else cout<< "Data " << number << " tidak ditemukan!!"<< endl;            
            system("pause");
            system("cls");
            goto menu;
        case 5:
            cout<< endl;
            cout<<"Urutan Data Tree secara Postorder"<< endl;
            cout<<"================================"<< endl;
            printPostorder(root);
            cout<< endl;
            system("pause");
            system("cls");
            goto menu;
    }
}
