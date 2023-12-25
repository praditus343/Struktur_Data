#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node *simpul;
struct node {
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
void Urutkan(simpul &DL);

int main() {
    char huruf, huruf2;
    simpul DL = NULL;
    int i, n;
    int menu;

    cout << "Nama\t: Praditus Egi Danuarta\nNIM\t: 22.11.4662\n\n";
    cout << "== OPERASI PADA DOUBLY LINKED LIST ==\n\n";

    do {
        cout << "Menu:\n";
        cout << "1. Sisip Simpul Di Depan\n";
        cout << "2. Sisip Simpul Di Belakang\n";
        cout << "3. Sisip Simpul Di Tengah Setelah Simpul Tertentu\n";
        cout << "4. Sisip Simpul Di Tengah Sebelum Simpul Tertentu\n";
        cout << "5. Hapus Simpul Depan\n";
        cout << "6. Hapus Simpul Belakang\n";
        cout << "7. Hapus Simpul Tengah\n";
        cout << "8. Urutkan\n";
        cout << "9. Keluar\n";
        cout << "Pilih menu (1-9): ";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "\n====\tSisip Simpul Di Depan\t====\n";
                cout << "Masukkan Huruf: ";
                cin >> huruf;
                Sisip_Depan(DL, huruf);
                Cetak(DL);
                cout << endl;
                break;
            case 2:
                cout << "\n====\tSisip Simpul Di Belakang\t====\n";
                cout << "Masukkan Huruf: ";
                cin >> huruf;
                Sisip_Belakang(DL, huruf);
                Cetak(DL);
                cout << endl;
                break;
            case 3:
                cout << "\n====\tSisip Simpul Di Tengah Setelah Simpul Tertentu\t====\n";
                cout << "Masukkan Huruf yang disisipkan: ";
                cin >> huruf;
                cout << "Disisip Setelah Huruf: ";
                cin >> huruf2;
                cout << huruf << " Disisip Setelah " << huruf2 << endl;
                Sisip_Tengah1(DL, huruf, huruf2);
                Cetak(DL);
                cout << endl;
                break;
            case 4:
                cout << "\n====\tSisip Simpul Di Tengah Sebelum Simpul Tertentu\t====\n";
                cout << "Masukkan Huruf: ";
                cin >> huruf;
                cout << "Disisip Sebelum Huruf: ";
                cin >> huruf2;
                cout << huruf << " Disisip Sebelum " << huruf2 << endl;
                Sisip_Tengah2(DL, huruf, huruf2);
                Cetak(DL);
                cout << endl;
                break;
            case 5:
                cout << "\n====\tHapus Simpul Depan\t====\n";
                Hapus_Depan(DL);
                Cetak(DL);
                cout << endl;
                break;
            case 6:
                cout << "\n====\tHapus Simpul Belakang\t====\n";
                Hapus_Belakang(DL);
                Cetak(DL);
                cout << endl;
                break;
            case 7:
                cout << "\n====\tHapus Simpul Tengah\t====\n";
                cout << "Masukkan Huruf Tengah Yang Akan Dihapus: ";
                cin >> huruf;
                Hapus_Tengah(DL, huruf);
                Cetak(DL);
                cout << endl;
                break;

            case 8:
                cout << "\n====\tPengurutan Doubly Linked List\t====\n";
                Urutkan(DL);
                cout << "Hasil Pengurutan:\n";
                Cetak(DL);
                cout << endl;
                break;
            case 9:
                cout << "\nTerima kasih! Program selesai.\n";
                break;
            default:
                cout << "\nInput tidak valid. Silakan pilih menu 1-8.\n";
                break;
        }

        cout << endl;

    } while (menu != 9);

    return 0;
}

// Implementasi fungsi sisip simpul di depan
void Sisip_Depan(simpul &DL, char elemen) {
    simpul baru;
    baru = (simpul) malloc(sizeof(node));
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

// Implementasi fungsi sisip simpul di belakang
void Sisip_Belakang(simpul &DL, char elemen) {
    simpul bantu, baru;
    baru = (simpul) malloc(sizeof(node));
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

// Implementasi fungsi sisip simpul di tengah setelah simpul tertentu
void Sisip_Tengah1(simpul &DL, char elemen1, char elemen2) {
    simpul bantu, baru;
    baru = (simpul) malloc(sizeof(node));
    baru->Isi = elemen1;
    baru->kanan = NULL;
    baru->kiri = NULL;
    if (DL == NULL)
        cout << "List kosong" << endl;
    else {
        bantu = DL;
        while (bantu->Isi != elemen2 && bantu != NULL)
            bantu = bantu->kanan;
        if (bantu != NULL) {
            baru->kanan = bantu->kanan;
            baru->kiri = bantu;
            if (bantu->kanan != NULL)
                bantu->kanan->kiri = baru;
            bantu->kanan = baru;
        } else {
            cout << "Simpul " << elemen2 << " tidak ditemukan." << endl;
        }
    }
}

// Implementasi fungsi sisip simpul di tengah sebelum simpul tertentu
void Sisip_Tengah2(simpul &DL, char elemen1, char elemen2) {
    simpul bantu, baru;
    baru = (simpul) malloc(sizeof(node));
    baru->Isi = elemen1;
    baru->kanan = NULL;
    baru->kiri = NULL;
    if (DL == NULL)
        cout << "List kosong" << endl;
    else {
        bantu = DL;
        while (bantu->Isi != elemen2 && bantu != NULL)
            bantu = bantu->kanan;
        if (bantu != NULL) {
            baru->kanan = bantu;
            baru->kiri = bantu->kiri;
            if (bantu->kiri != NULL)
                bantu->kiri->kanan = baru;
            bantu->kiri = baru;
        } else {
            cout << "Simpul " << elemen2 << " tidak ditemukan." << endl;
        }
    }
}

// Implementasi fungsi mencetak isi linked list
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

// Implementasi fungsi hapus simpul depan
void Hapus_Depan(simpul &DL) {
    simpul hapus;
    if (DL == NULL)
        cout << "Linked List Kosong" << endl;
    else {
        hapus = DL;
        DL = DL->kanan;
        if (DL != NULL)
            DL->kiri = NULL;
        hapus->kanan = NULL;
        free(hapus);
    }
}

// Implementasi fungsi hapus simpul belakang
void Hapus_Belakang(simpul &DL) {
    simpul bantu, hapus;
    if (DL == NULL)
        cout << "Linked List Kosong" << endl;
    else {
        bantu = DL;
        while (bantu->kanan != NULL)
            bantu = bantu->kanan;
        hapus = bantu;
        if (bantu->kiri != NULL)
            bantu->kiri->kanan = NULL;
        else
            DL = NULL;
        hapus->kiri = NULL;
        free(hapus);
    }
}

// Implementasi fungsi hapus simpul tengah
void Hapus_Tengah(simpul &DL, char elemen) {
    simpul bantu, hapus;
    if (DL == NULL)
        cout << "Linked List Kosong" << endl;
    else {
        bantu = DL;
        while (bantu != NULL && bantu->Isi != elemen)
            bantu = bantu->kanan;
        if (bantu != NULL) {
            if (bantu->kiri != NULL)
                bantu->kiri->kanan = bantu->kanan;
            else
                DL = bantu->kanan;
            if (bantu->kanan != NULL)
                bantu->kanan->kiri = bantu->kiri;
            hapus = bantu;
            hapus->kanan = NULL;
            hapus->kiri = NULL;
            free(hapus);
        } else {
            cout << "Simpul " << elemen << " tidak ditemukan." << endl;
        }
    }
}

// Implementasi fungsi pengurutan Doubly Linked List (Bubble Sort)
void Urutkan(simpul &DL) {
    if (DL == NULL || DL->kanan == NULL) {
        // Linked List kosong atau hanya memiliki satu simpul
        return;
    }

    bool swapped;
    simpul current;
    simpul last = NULL;

    do {
        swapped = false;
        current = DL;

        while (current->kanan != last) {
            if (current->Isi > current->kanan->Isi) {
                // Tukar posisi simpul jika urutannya salah
                char temp = current->Isi;
                current->Isi = current->kanan->Isi;
                current->kanan->Isi = temp;
                swapped = true;
            }

            current = current->kanan;
        }

        last = current;

    } while (swapped);
}


