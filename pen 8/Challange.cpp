#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct Data {
    int nilai;
    Data *next;
} Data;

Data *head;
Data *tail;

void awal() {
    head = NULL;
}

bool isEmpty() {
    if (head == NULL)
        return true;
    return false;
}

void tambahDataDepan(int DataBaru) {
    Data *baru;
    baru = new Data;
    baru->nilai = DataBaru;
    baru->next = NULL;
    if (isEmpty()) {
        head = baru;
        head->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
    cout << "Data Depan " << DataBaru << " Masuk" << endl;
}

void tambahDataBelakang(int DataBaru) {
    Data *baru, *bantu;
    baru = new Data;
    baru->nilai = DataBaru;
    baru->next = NULL;
    if (isEmpty()) {
        head = baru;
        head->next = NULL;
    } else {
        bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
    cout << "Data Belakang " << DataBaru << " Masuk" << endl;
}

void hapusDepan() {
    Data *hapus;
    int d;
    if (!isEmpty()) {
        if (head->next != NULL) {
            hapus = head;
            d = hapus->nilai;
            head = hapus->next;
            delete hapus;
        } else {
            d = head->nilai;
            head = NULL;
        }
        cout << d << " Terhapus" << endl;
    } else
        cout << "Masih Kosong" << endl;
}

void hapusBelakang() {
    Data *hapus, *bantu;
    int tmp;
    if (!isEmpty()) {
        if (head->next != NULL) {
            bantu = head;
            while (bantu->next->next != NULL) {
                bantu = bantu->next;
            }
            hapus = bantu->next;
            tmp = hapus->nilai;
            bantu->next = NULL;
            delete hapus;
        } else {
            tmp = head->nilai;
            head = NULL;
        }
        cout << tmp << " Terhapus" << endl;
    } else
        cout << "Masih Kosong" << endl;
}

void tambahTengah(int posisi, int DataBaru) {
    if (isEmpty() || posisi <= 1) {
        tambahDataDepan(DataBaru);
    } else if (posisi >= panjang()) {
        tambahDataBelakang(DataBaru);
    } else {
        Data *baru, *bantu;
        baru = new Data;
        baru->nilai = DataBaru;
        bantu = head;
        for (int i = 1; i < posisi - 1; i++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
        cout << "Data " << DataBaru << " pada posisi " << posisi << " Masuk" << endl;
    }
}

void hapusTengah(int posisi) {
    if (isEmpty() || posisi <= 1) {
        hapusDepan();
    } else if (posisi >= panjang()) {
        hapusBelakang();
    } else {
        Data *hapus, *bantu;
        int tmp;
        bantu = head;
        for (int i = 1; i < posisi - 1; i++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        tmp = hapus->nilai;
        bantu->next = hapus->next;
        delete hapus;
        cout << tmp << " Terhapus" << endl;
    }
}

void Cetak() {
    if (!isEmpty()) {
        Data *bantu;
        bantu = head;
        do {
            cout << bantu->nilai << " ";
            bantu = bantu->next;
        } while (bantu != NULL);
        cout << endl;
    }
}

int panjang() {
    int count = 0;
    if (!isEmpty()) {
        count = 1;
        Data *bantu;
        bantu = head;
        if (bantu->next == NULL) {
            count = 1;
        } else {
            do {
                count++;
                bantu = bantu->next;
            } while (bantu->next != NULL);
        }
    } else {
        count = 0;
    }
    return count;
}

int main() {
    awal();
    tambahDataBelakang(5);
    tambahDataDepan(7);
    tambahDataBelakang(17);
    tambahDataBelakang(1);
    tambahDataBelakang(27);
    tambahDataBelakang(10);

    cout << "Data pada single linked list non circular:" << endl;
    Cetak();

    cout << "Data paling depan dihapus:" << endl;
    hapusDepan();

    cout << "Data pada single linked list non circular:" << endl;
    Cetak();

    cout << "Data paling belakang dihapus:" << endl;
    hapusBelakang();

    cout << "Data pada single linked list non circular:" << endl;
    Cetak();

    cout << "Panjang linked list :" << endl;
    cout << panjang() << endl;

    tambahTengah(2, 8);

    cout << "Data setelah penambahan di tengah:" << endl;
    Cetak();

    hapusTengah(3);

    cout << "Data setelah penghapusan di tengah:" << endl;
    Cetak();

    cout << "\n\n Praditus Egi Danuarta - 22.11.4662";
    return 0;
}
