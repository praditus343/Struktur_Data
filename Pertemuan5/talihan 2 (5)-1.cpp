#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Antrian
{
private:
    

public:
    vector<string> data;
    int depan, belakang;
    int maksElemen;
    // Konstruktor
    Antrian(int ukuran)
    {
        depan = 0;
        belakang = 0;
        maksElemen = ukuran;
        data.resize(ukuran); // Ukuran vector
    }

    // Memasukkan data ke antrian
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

    // Menghapus data dari antrian
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

    // Mengecek apakah antrian kosong atau tidak
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

    int pilihan;
    string nama;

    while (true)
    {
        // Menampilkan menu
        cout << "Menu: " << endl;
        cout << "1. Tambah data" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Keluar" << endl;

        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        // Memproses pilihan
        switch (pilihan)
        {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                daftar.insert(nama);
                break;
            case 2:
                nama = daftar.remove();
                if (nama != "")
                    cout << "Data yang dihapus: " << nama << endl;
                break;
            case 3:
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
        cout << endl;
        // Menampilkan antrian
        cout << "Antrian: ";
        if (daftar.empty())
        {
            cout << "kosong" << endl;
        }
        else
        {
            // Menampilkan data dari depan ke belakang
            int i = daftar.empty() ? daftar.depan : daftar.depan + 1;
            for (; i <= daftar.belakang; i++)
            {
                cout << daftar.data[i] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}
