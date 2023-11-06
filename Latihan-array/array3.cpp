#include <iostream>

using namespace std;

//prototype fungsi
void cetakElemenArray(int array[], int jumlahElemenArray);
int getNilaiTerbesar(int array[], int jumlahElemenArray);

int main() {
	
	//deklarasi array dan var kosong
	int jumlahArray, nilaiTerkecil;
	
	cout << "Masukan nilai Elemen Array yang diinginkan : ";
	cin >> jumlahArray;
	
	int nilaiArray[jumlahArray];
	
	//menampilkan array dan memasukkannya
	for (int i = 0; i < jumlahArray; i++) {
		cout << "Array ke " << i+1 << " = ";
		cin >> nilaiArray[i];
		
		//validate nilai terkecil
		if(i==0) {
			nilaiTerkecil = nilaiArray[0];
		}
		if(nilaiArray[i] < nilaiTerkecil) {
			nilaiTerkecil = nilaiArray[i];
		}
	}
	//hitung jumlah element array
	int jumlahElemenArray = sizeof(nilaiArray) / sizeof(int);
	
	//cari nilai terbesar
	int nilaiTerbesar = getNilaiTerbesar(nilaiArray, jumlahElemenArray);
	
	cout << "Nilai dari daftar array adalah berikut :" << endl << endl;
	
	//cetak elemen array
	cetakElemenArray(nilaiArray, jumlahElemenArray);
	
	cout <<"Nilai terbesar : " << nilaiTerbesar << endl;
	cout <<"Nilai Terkecil : " << nilaiTerkecil << endl << endl;
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
