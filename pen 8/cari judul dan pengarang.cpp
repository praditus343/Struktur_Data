#include <iostream>
using namespace std;

struct Buku{
    string judul, pengarang;
    int tahunTerbit;
    Buku *next;
};

Buku *head, *tail, *cur, *newNode, *del, *before;

void createSingleLinkedList(string judul, string pengarang, int tB){
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
    head->next = NULL;
    tail = head;
}

int countSingleLinkedList(){
    cur = head;
    int jumlah = 0;
    while( cur != NULL ){
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

void addFirst(string judul, string pengarang, int tB){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = head;
    head = newNode;
}

void addLast(string judul, string pengarang, int tB){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void addMiddle(string judul, string pengarang, int tB, int posisi){
    if( posisi < 1 || posisi > countSingleLinkedList() ){
        cout << "Posisi diluar jangkauan" << endl;
    } else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    } else{
        newNode = new Buku();
        newNode->judul = judul;
        newNode->pengarang = pengarang;
        newNode->tahunTerbit = tB;

        cur = head;
        int nomor = 1;
        while( nomor < posisi - 1 ){
            cur = cur->next;
            nomor++;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

void removeFirst(){
    del = head;
    head = head->next;
    delete del;
}

void removeLast(){
    del = tail;
    cur = head;
    while( cur->next != tail ){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

void removeMiddle(int posisi){
    if (posisi < 1 || posisi > countSingleLinkedList() ){
        cout << "Posisi diluar jangkauan"<< endl;
    } else if( posisi == 1){
        cout << "Posisi bukan posisi tengah"<< endl;
    } else{
        int nomor = 1;
        cur = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                before = cur;
            }
            if (nomor == posisi){
                del = cur;
            }
            cur = cur->next;
            nomor++;
        }
        before->next = cur;
        delete del;
    }
}

void changeFirst(string judul, string pengarang, int tB){
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
}

void changeLast(string judul, string pengarang, int tB){
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->tahunTerbit = tB;
}

void changeMiddle(string judul, string pengarang, int tB, int posisi){
    if ( posisi < 1 || posisi > countSingleLinkedList() ){
        cout << "Posisi diluar jangkauan"<< endl;
    } else if(posisi == 1 || posisi == countSingleLinkedList() ){
        cout << "Posisi bukan posisi tengah" << endl;
    } else{
        cur = head;
        int nomor = 1;
        while( nomor < posisi){
            cur = cur->next;
            nomor++;
        }
        cur->judul = judul;
        cur->pengarang = pengarang;
        cur->tahunTerbit = tB;
    }
}

void searchByTitle(string judul){
    cur = head;
    int posisi = 1;
    bool found = false;
    while (cur != NULL) {
        if (cur->judul == judul) {
            cout << "Buku dengan judul " << judul << " ditemukan pada posisi " << posisi << endl;
            cout << "Judul: " << cur->judul << endl;
            cout << "Pengarang: " << cur->pengarang << endl;
            cout << "Tahun Terbit: " << cur->tahunTerbit << endl;
            found = true;
        }
        cur = cur->next;
        posisi++;
    }
    if (!found) {
        cout << "Buku dengan judul " << judul << " tidak ditemukan" << endl;
    }
}

void searchByAuthor(string pengarang){
    cur = head;
    int posisi = 1;
    bool found = false;
    while (cur != NULL) {
        if (cur->pengarang == pengarang) {
            cout << "Buku dengan pengarang " << pengarang << " ditemukan pada posisi " << posisi << endl;
            cout << "Judul: " << cur->judul << endl;
            cout << "Pengarang: " << cur->pengarang << endl;
            cout << "Tahun Terbit: " << cur->tahunTerbit << endl;
            found = true;
        }
        cur = cur->next;
        posisi++;
    }
    if (!found) {
        cout << "Buku dengan pengarang " << pengarang << " tidak ditemukan" << endl;
    }
}

void printSingleLinkedList() {
    cout << "Jumlah data ada : "<< countSingleLinkedList() << endl;
    cur = head;
    while( cur !=NULL ){
        cout << "Judul Buku : "<< cur->judul << endl;
        cout << "Pengarang Buku "<< cur ->pengarang << endl;
        cout << "Tahun Terbit Buku : "<< cur->tahunTerbit << endl;
        cur = cur->next;
    }
}

int main(){
    cout << "Praditus Egi Danuarta - 22.11.4662" << endl;
    cout << "---------------------------------" << endl;

    createSingleLinkedList("Kata","Geez & Aan", 2018);

    printSingleLinkedList();

    cout << "\n"<< endl;

    addFirst("Dia adalah Kakakku", "Tere Liye", 2009);

    printSingleLinkedList();

    cout << "\n"<< endl;

    addLast("Aroma Karsa", "Dee Lestari", 2018);

    printSingleLinkedList();

    cout << "\n"<< endl;
    removeFirst();

    printSingleLinkedList();

    cout << "\n"<< endl;

    addLast("11.11", "Fiersa Besari", 2018);

    printSingleLinkedList();

    cout << "\n"<< endl;

    removeLast();

    printSingleLinkedList();

    cout << "\n"<< endl;

    changeFirst("Berhenti di Kamu", "Gia Pratama", 2018);

    printSingleLinkedList();

    cout << "\n" << endl;

    addMiddle("Bumi Manusia", "Pramoedya Anata Toer", 2005, 2);

    printSingleLinkedList();

    cout << "\n" << endl;

    addMiddle("Negeri 5 Menara", "Ahmad Fuadi", 2009, 2);

    printSingleLinkedList();

    cout << "\n" << endl;

    removeMiddle(5);

    printSingleLinkedList();

    cout << "\n" << endl;

    changeMiddle("Sang Pemimpi", "Andrea Hirata", 2006, 2);

    printSingleLinkedList();

    cout << "\n" << endl;

    searchByTitle("Kata");
    searchByAuthor("Gia Pratama");

    cout << "\n" << endl;
}

