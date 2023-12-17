#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Antrian

{
	
private:
 vector<string> data;
 int depan, belakang;
 int maksElemen;
public:
		
 // Konstruktor
 Antrian(int ukuran)
 {
 depan = 0;
 belakang = 0;
 maksElemen = ukuran;
 data.resize(ukuran); // Ukuran vector
 }
 
 // Memasukkan data ke antrian
 // Nilai balik tidak ada
 void insert(string x)
 {
 int posisiBelakang;
 // Geser belakang ke posisi berikutnya
 if (belakang == maksElemen)
 posisiBelakang = 1;
 else
 posisiBelakang = belakang + 1;
 // Cek belakang apa sama dengan Depan
 if (posisiBelakang == depan)
 cout << "Antrian penuh" << endl;
 else
 {
 belakang = posisiBelakang;
 // Masukkan data
 data[belakang] = x;
 }
 }
 string remove(void)
 {
 if (empty())
 {
 cout << "Antrian kosong" << endl;
 return "";
 }
 if (depan == maksElemen)
 depan = 1;
 else
 depan = depan + 1;
 return data[depan];
 }
 bool empty(void)
 {
 if (depan == belakang)
 return true;
 else
 return false;
 }
};
int main()
{
 int ukuran = 10;
 Antrian daftar(ukuran); // Buat objek
 // Masukkan 5 buah nama
 daftar.insert("Ikhwan Wibul");
 daftar.insert("Dico cabul");
 daftar.insert("Syamsul Sadboy");
 daftar.insert("Bagas Racing");
 daftar.insert("egibaik");
 // Kosongkan isi antrian dan tampilkan
 while (! daftar.empty())
 {
 string nama = daftar.remove();
 cout << nama << endl;
 }
 	cout << "\n22.11.4662 - Praditus Egi Danuarta\n" << endl;
 return 0;
}
