#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct MataKuliah {
    string kode;
    string nama;
    int sks;
    char nilai;
};

struct Mahasiswa {
    string nim;
    string nama;
    vector<MataKuliah> mk;
};

void tampilkanKHS(const Mahasiswa& mhs);

int main() {
    Mahasiswa mhs;
    cout << "Program KHS Mahasiswa" << endl;
    cout << "Jumlah mahasiswa: " << endl;
    cout << "---------------------------------" << endl;
    cout << "NIM : ";
    getline(cin, mhs.nim);
    cout << "Nama: ";
    getline(cin, mhs.nama);

    int jumlahMK;
    cout << "Jumlah mata kuliah diambil: ";
    cin >> jumlahMK;
    cin.ignore();

    for (int i = 0; i < jumlahMK; i++) {
        MataKuliah mk;
        cout << "\nMata Kuliah ke-" << i + 1 << endl;
        cout << "Kode: ";
        getline(cin, mk.kode);
        cout << "Nama: ";
        getline(cin, mk.nama);
        cout << "Bobot SKS: ";
        cin >> mk.sks;
        cout << "Nilai: ";
        cin >> mk.nilai;
        cin.ignore();

        mhs.mk.push_back(mk);
    }

    tampilkanKHS(mhs);

    return 0;
}

void tampilkanKHS(const Mahasiswa& mhs) {
    int totalSKS = 0;
    double totalNilai = 0;
    double ipk = 0;

    cout << "+---------------------------------------------------------+" << endl;
    cout << "|                     Kartu Hasil Studi                   |" << endl;
    cout << "+---------------------------------------------------------+" << endl;
    cout << "| NIM          : " << mhs.nim << "                             |" << endl;
    cout << "| Nama         : " << mhs.nama << "                       |" << endl;
    cout << "+---------------------------------------------------------+" << endl;
    cout << "| Kode  |    Nama Mata Kuliah        | SKS | Nilai | Bobot |" << endl;
    cout << "+---------------------------------------------------------+" << endl;

    for (const MataKuliah& mk : mhs.mk) {
        int bobot = (mk.nilai == 'A') ? 4 : (mk.nilai == 'B') ? 3 :
            (mk.nilai == 'C') ? 2 : (mk.nilai == 'D') ? 1 : 0;
        int sks = mk.sks;
        int nilai = bobot * sks;
        totalSKS += sks;
        totalNilai += nilai;

        cout << "| " << left << setw(6) << mk.kode << " | " << left << setw(25) << mk.nama << " | " <<
            left << setw(3) << mk.sks << " | " << left << setw(5) << mk.nilai << " | " << left << setw(5) << bobot << " |" << endl;
    }

    cout << "+---------------------------------------------------------+" << endl;
    cout << "| Jumlah SKS Total                 | " << right << setw(3) << totalSKS << " |       |       |" << endl;
    if (totalSKS > 0) {
        ipk = totalNilai / totalSKS;
        cout << "| Indeks Prestasi Kumulatif (IPK)   |       |       | " << setprecision(2) << fixed << setw(5) << ipk << " |" << endl;
    }
    cout << "+---------------------------------------------------------+" << endl;
    cout << "|                          Praditus Egi Danuarta - 22.11.4662                          |" << endl;
    cout << "+---------------------------------------------------------+" << endl;
}