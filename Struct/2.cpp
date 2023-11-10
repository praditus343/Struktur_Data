#include <iostream>
using namespace std;

struct mahasiswa {
	string nama;
	string jurusan;
};


int main(){
	system("cls");
	mahasiswa mhs;
	
	cout << "==++ Pendaftaran Mahasiswa Baru ++==" << endl;
	
	cout << "Nama	: ";
	getline(cin, mhs.nama);
	cout << "Jurusan	: ";
	getline(cin, mhs.jurusan);	
	
	cout << "\nDATA MAHASISWA" << endl;
	cout << "---------------------" << endl;
	cout << "Nama	: " << mhs.nama << endl;
	cout << "jurusan	: " << mhs.jurusan << endl << endl;
	
	cout << "22.11.4662 - Praditus Egi Danuarta";
	return 0;
} 
