#include <iostream>
using namespace std;

int main()
{
    char kampus[] = "UNIVERSITAS AMIKOM";

    // hitung jumlah elemen array kampus
    int length = sizeof(kampus) / sizeof(char);

    // Tampilkan nilai array kampus
    for (int i = 0; i < length; i++)
    {
        cout << kampus[i];
    }
    cout << "Jika dibalik menjadi" << endl
         << endl;

    // TODO tampilkan nilai kampus secara terbalik menggunakan pointer
    char *p = kampus + length - 1;
    while (p >= kampus)
    {
        cout <<*p;
        p--;
    }
    cout << endl;
    cout << "Praditus Egi Danuarta - 22.11.4662" << endl;
    cout << endl;
    cout << endl
         << endl;
    system("pause");
    return 0;
}
