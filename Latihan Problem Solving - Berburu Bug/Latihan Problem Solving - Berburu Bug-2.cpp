#include <iostream>
using namespace std;

int main() {
    string nama[100];
    string Mk[100];
    int nilai[100];
    int jumblah;

    cout<<"Jumblah Mahasiswa : ";
    cin>> jumblah;
    for(int i=1; i<=jumblah;i++){
    cout<<"Masukan Nama Mahasiswa : ";
    cin>> nama[i];
    cout<<"Masukan Mata Kuliah : ";
    cin>> Mk[i];
    cout<<"Masukan Nilai Mahasiswa : ";
    cin>> nilai[i];
    cout<<endl;
    }


    cout<<"\nTampilkan data : "<<endl;
    for(int i=1; i<=jumblah; i++){
    cout<<"Nama : "<<nama[i]<<", Nilai Mata Kuliah "<<Mk[i]<<" adalah "<<nilai[i]<<endl;
    }
    return 0;
}