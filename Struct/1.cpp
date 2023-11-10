#include <iostream>
using namespace std;

struct MataKuliah {
	string kode;
	string nama;
	int bobot;
};
struct Mahasiswa {
	string nim;
	string nama;
	double ipk;
	MataKuliah mata_kuliah;
};
Mahasiswa mhs;

int main(){
	system("cls");
	mhs.mata_kuliah.kode = "ST015";
	mhs.mata_kuliah.nama = "STRUKTUR DATA";
	mhs.mata_kuliah.bobot = 4;
	
	cout << "Kode MK : " << mhs.mata_kuliah.kode << endl;
	cout << "Kode MK : " << mhs.mata_kuliah.nama  << endl;
	cout << "Kode MK : " << mhs.mata_kuliah.bobot << endl << endl;
	
	mhs.nim = "22.11.4662";
	mhs.nama = "Praditus Egi Danuarta";
	mhs.ipk = 3.99;
	
	cout << "NIM : " << mhs.nim << endl;
	cout << "Nama : " << mhs.nama << endl;
	cout << "IPK : " << mhs.ipk << endl << endl;
	
	cout << "22.11.4662 - Praditus Egi Danuarta";
	return 0;
} 
