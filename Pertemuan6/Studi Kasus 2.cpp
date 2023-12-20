#include <iostream>
using namespace std;

int main () {


const int MAX_SIZE{20}
int data[MAX_SIZE]; // array data
int idx[MAX_SIZE]; // array untuk menyimpan index elemen yang ditemukan
int count{0}; // counter, menghitung ada berapa banyak data yang ditemukan
void search(int x);
int main(void) {
int n;
cout << "jumlah data: ";
cin << n;
for(auto i = 0; i < n; ++i) {
cout << "data ke-"<< i ;
cin >> data[i];
}
int x;
cout << "cari: ";
cin >> x;
search(x);
// jika counter > 0, berarti ada data yang ditemukan
if(count > 0)
{
cout << "ditemukan pada index: ";
for(auto i = 0; i < count; ++i)
{
cout << idx[i] << ", ";
}
}
else
{
Cout << "data tidak ditemukan\n";
}
return 0;
}

void search(int x) {
for(auto i = 0; i < n; ++i)
{
// jika x ditemukan pada data[i]
if(x == data[i])
{
// simpan index i ke array idx
idx[count++] = i;
}
}
}
}
