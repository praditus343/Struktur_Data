#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node *simpul;
struct node{
    char Isi;
    simpul kanan;
    simpul kiri;
};

// Prototype function
void Sisip_Depan(simpul &DL, char elemen);
void Sisip_Belakang(simpul &DL, char elemen);
void Sisip_Tengah1(simpul &DL, char elemen1, char elemen2);
void Sisip_Tengah2(simpul &DL, char elemen1, char elemen2);
void Hapus_Depan(simpul &DL);
void Hapus_Belakang(simpul &DL);
void Hapus_Tengah(simpul &DL, char elemen);
void Cetak(simpul DL);

int main() {
    char huruf, huruf2;
    simpul DL = NULL;
    int i, n;
    cout<<"Nama\t: Praditus Egi Danuarta\nNIM\t: 22.11.4662\n\n";
    cout << "== OPERASI PADA DOUBLY LINKED LIST ==\n\n";

    // Sisip Depan
    cout << "====\tPercobaan 1\t====\n";
    cout << "==== Penyisipan Simpul Di Depan ====\n\n";
    cout << "Masukkan jumlah data: ";
    cin >> n;
    for (i = 1; i <= n; i++) {
        cout << "Masukkan Huruf: ";
        cin >> huruf;
        Sisip_Depan(DL, huruf);
    }
    Cetak(DL);

    // Sisip Belakang
    cout << "\n\n====\tPercobaan 2\t====\n";
    cout << "==== Penyisipan Simpul Di Belakang ====\n\n";
    cout << "Masukkan jumlah data: ";
    cin >> n;
    cout << endl;
    for (i = 1; i <= n; i++) {
        cout << "Masukkan Huruf: ";
        cin >> huruf;
        Sisip_Belakang(DL, huruf);
    }
    Cetak(DL);

    // Sisip Simpul Setelah Simpul Tertentu
    cout << "\n\n====\tPercobaan 3\t====\n";
    cout << "==== Penyisipan Simpul Di Tengah Sebelum Node Tertentu ====\n\n";
    cout << "Masukkan Huruf yang disisipkan: ";
    cin >> huruf;
    cout << "Disisip Setelah Huruf: ";
    cin >> huruf2;
    cout << huruf << " Disisip Setelah " << huruf2 << endl;
    Sisip_Tengah1(DL, huruf, huruf2);
    Cetak(DL);

    // Sisip Simpul Sebelum Simpul Tertentu
    cout << "\n\n====\tPercobaan 4\t====\n";
    cout << "==== Penyisipan Simpul Di Tengah Setelah Node Tertentu ====\n\n";
    cout << "Masukkan Huruf: ";
    cin >> huruf;
    cout << "Disisip Sebelum Huruf: ";
    cin >> huruf2;
    cout << huruf << " Disisip Sebelum " << huruf2 << endl;
    Sisip_Tengah2(DL, huruf, huruf2);
    Cetak(DL);

    // Hapus Simpul Depan
    cout << "\n\n=====\tPercobaan 5\t====\n";
    cout << "=== Hapus Simpul Depan ====\n\n";
    cout << "Setelah Hapus Simpul Depan\n";
    Hapus_Depan(DL);
    Cetak(DL);

    // Hapus Simpul Belakang
    cout << "\n\n====\tPercobaan 6\t====\n";
    cout << "==== Hapus Simpul Belakang ====\n\n";
    cout << "Setelah Hapus Simpul Belakang\n";
    Hapus_Belakang(DL);
    Cetak(DL);

    // Hapus Simpul Tengah
    cout << "\n\n====\tPercobaan 7\t====\n";
    cout << "==== Hapus Simpul Tengah ====\n\n";
    cout << "Masukkan Huruf Tengah Yang Akan Dihapus: ";
    cin >> huruf;
    Hapus_Tengah(DL, huruf);
    Cetak(DL);

    return 0;
}

// Function Sisip Simpul Di Depan
void Sisip_Depan(simpul &DL, char elemen) {
    simpul baru;
    baru = (simpul) malloc(sizeof(simpul));
    baru->Isi = elemen;
    baru->kanan = NULL;
    baru->kiri = NULL;
    if (DL == NULL)
        DL = baru;
    else {
        baru->kanan = DL;
        DL->kiri = baru;
        DL = baru;
    }
}

// Function Sisip Simpul Di Belakang
void Sisip_Belakang(simpul &DL, char elemen) {
    simpul bantu, baru;
    baru = (simpul) malloc(sizeof(simpul));
    baru->Isi = elemen;
    baru->kanan = NULL;
    baru->kiri = NULL;
    if (DL == NULL)
        DL = baru;
    else {
        bantu = DL;
        while (bantu->kanan != NULL)
            bantu = bantu->kanan;
        bantu->kanan = baru;
        baru->kiri = bantu;
    }
}

// Sisip Simpul Tengah Setelah Simpul Tertentu
void Sisip_Tengah1(simpul &DL, char elemen1, char elemen2) {
    simpul bantu, baru;
    baru = (simpul) malloc(sizeof(simpul));
    baru->Isi = elemen1;
    baru->kanan = NULL;
    baru->kiri = NULL;
    if (DL == NULL)
        cout << "List kosong" << endl;
    else {
        bantu = DL;
        while (bantu->Isi != elemen2)
            bantu = bantu->kanan;
        baru->kanan = bantu->kanan;
        baru->kiri = baru;
        baru->kiri = bantu;
        bantu->kanan->kiri = baru;
        bantu->kanan = baru;
    }
}

// Sisip Simpul Tengah Sebelum Simpul Tertentu
void Sisip_Tengah2(simpul &DL, char elemen1, char elemen2) {
    simpul bantu, baru;
    baru = (simpul) malloc(sizeof(simpul));
    baru->Isi = elemen1;
    baru->kanan = NULL;
    baru->kiri = NULL;
    if (DL == NULL)
        cout << "List kosong" << endl;
    else {
        bantu = DL;
        while (bantu->Isi != elemen2)
            bantu = bantu->kanan;
        baru->kanan = bantu->kanan;
        baru->kiri = bantu;
        bantu->kanan->kiri = baru;
        bantu->kanan = baru;
    }
}

// Function Mencetak Isi Linked List
void Cetak(simpul DL) {
    simpul bantu;
    if (DL == NULL)
        cout << "Linked List Kosong" << endl;
    else {
        bantu = DL;
        cout << "Isi Linked List: ";
        while (bantu->kanan != NULL) {
            cout << bantu->Isi << " <--> ";
            bantu = bantu->kanan;
        }
        cout << bantu->Isi;
    }
}

// Function Hapus Simpul Depan
void Hapus_Depan(simpul &DL) {
    simpul Hapus;
    if (DL == NULL)
        cout << "Linked List Kosong";
    else {
        Hapus = DL;
        DL = DL->kanan;
        DL->kiri = NULL;
        Hapus->kanan = NULL;
        free(Hapus);
    }
}

// Function Hapus Simpul Belakang
void Hapus_Belakang(simpul &DL) {
    simpul bantu, hapus;
    if (DL == NULL)
        cout << "Linked List Kosong";
    else {
        bantu = DL;
        while (bantu->kanan->kanan != NULL)
            bantu = bantu->kanan;
        hapus = bantu->kanan;
        bantu->kanan = NULL;
        hapus->kiri = NULL;
        free(hapus);
    }
}

// Function Hapus Simpul Tengah
void Hapus_Tengah(simpul &DL, char elemen) {
    simpul bantu, hapus;
    if (DL == NULL)
        cout << "Linked List Kosong";
    else {
        bantu = DL;
        while (bantu->kanan->Isi != elemen)
            bantu = bantu->kanan;
        hapus = bantu->kanan;
        bantu->kanan->kanan->kiri = bantu;
        bantu->kanan = bantu->kanan->kanan;
        hapus->kanan = NULL;
        hapus->kiri = NULL;
        free(hapus);
    }
}
