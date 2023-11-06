#include <iostream>

using namespace std;

//prototype fungsi
void cetakElemenArray(int array[], int jumlahElemenArray);
int getNilaiTerbesar(int array[], int jumlahElemenArray);

int main() {
	
	//deklarasi array plus inisialisasi
	int nilaiArray[] = {5,7,1,45,8,100,9,10,17};
	
	//hitung jumlah element array
	int jumlahElemenArray = sizeof(nilaiArray) / sizeof(int);
	
	//cari nilai terbesar
	int nilaiTerbesar = getNilaiTerbesar(nilaiArray, jumlahElemenArray);
	
	cout << "Nilai terbesar dari daftar array berikut :" << endl << endl;
	
	//cetak elemen array
	cetakElemenArray(nilaiArray, jumlahElemenArray);
	
	cout <<"Adalah : " << nilaiTerbesar << endl << endl;
	cout << "Praditus Egi Danuarta - 22.11.4662" << endl;
	system("pause");
	return 0;
}

void cetakElemenArray(int array[], int jumlahElemenArray) {
	for (int i = 0; i < jumlahElemenArray; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
}

int getNilaiTerbesar(int array[], int jumlahElemenArray) {
	int nilaiTerbesar = 0;
	for (int i = 0; i < jumlahElemenArray; i++) {
		if (nilaiTerbesar < array[i])
			nilaiTerbesar = array[i];
	}
	
	return nilaiTerbesar;
}
