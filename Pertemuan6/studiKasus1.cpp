#include <iostream>
using namespace std;

const int MAX_SIZE{20};
int data[MAX_SIZE]; // array data
int idx[MAX_SIZE]; // array untuk menyimpan index elemen yang ditemukan
int count{0}; // counter, menghitung ada berapa banyak data yang ditemukan

void search(int x, int n);

int main(void) {
    int n;
    cout << "\nPraditus Egi Danuarta - 22.11.4662" << endl;
    cout << "Jumlah data: ";
    cin >> n;

    // Input elemen array
    for(auto int i = 0; i < n; ++i) {
        cout << "Data ke-" << i << ": ";
        cin >> data[i];
    }

    int x;
    cout << "Cari nilai: ";
    cin >> x;
    search(x, n);

    // Jika counter > 0, berarti ada data yang ditemukan
    if(count > 0) {
        cout << "Data ditemukan pada index: ";
        for(auto int i = 0; i < count; ++i) {
            cout << idx[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Data tidak ditemukan\n";
    }

    return 0;
}

void search(int x, int n) {
    for(auto int i = 0; i < n; ++i) {
        // Jika x ditemukan pada data[i]
        if(x == data[i]) {
            // Simpan index i ke dalam array idx
            idx[count++] = i;
        }
    }
}
